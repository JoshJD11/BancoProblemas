#include<iostream> 
using namespace std;
#include<vector>

vector<vector<int>>llaves = {{-1,0},{0,-1}};

bool esValido(int i, int j, int filas, int columnas){return i>=0 && j>=0 && i<filas && j<columnas;}

bool idcmp(string& s1, string&s2){
    for(int i=0;i<(int)s1.size();i++){
        if(s1[i]!=s2[i]) return 0;
    } return 1;
}


class node{
    public:
        node* padre;
        string id;
        bool contado;
        node(int i, int j){
            this->padre = this;
            this->contado = false;
            this->id = to_string(i) + to_string(j);
        }
};


node* Find(node*A)
{
    return (idcmp(A->padre->id, A->id))? A : Find(A->padre);
}


void Union(node*A, node*B)
{
    node* FA = Find(A);
    node* FB = Find(B);
    
    if(FA->id != FB->id){
        FA -> padre = FB;
    }
}


int componentesDistintas(vector<vector<node*>>&componentesConexas, int filas, int columnas)
{
    int res = 0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(componentesConexas[i][j]!=nullptr){
                node* FA = Find(componentesConexas[i][j]);
                if(!FA->contado){
                    FA->contado = true;
                    res++;
                }
            }
        }
    }
    return res;
}


int main(){
    char Char;
    int caseNum = 1,filas,columnas;
    while(cin>>filas>>columnas)
    {
        vector<vector<char>>matriz(filas,vector<char>(columnas));
        vector<vector<node*>>componentesConexas(filas,vector<node*>(columnas, nullptr));
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                cin>>Char;
                matriz[i][j] = Char;
                if(Char == '-'){
                    componentesConexas[i][j] = new node(i,j);
                    for(int k=0;k<(int)llaves.size();k++){ 
                        int x = i+llaves[k][0], y = j+llaves[k][1];
                        if(esValido(x,y,filas,columnas) && matriz[x][y] == '-'){
                            Union(componentesConexas[i][j], componentesConexas[x][y]);
                        }
                    }
                }
            }
        }
        cout<<"Case "<<caseNum<<": "<<componentesDistintas(componentesConexas, filas, columnas)<<'\n';
        caseNum++;
        for (int ii = 0; ii < filas; ii++) {
            for (int iii = 0; iii < columnas; iii++) {
                delete componentesConexas[ii][iii];
            }
        }
    }

    return 0;
}