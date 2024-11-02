#include<iostream> //ACCEPTED!!!
#include<vector>
#include<stack>
using namespace std;


vector<vector<int>>llaves = {{0,1},{1,0},{-1,0},{0,-1}};


bool hayTrampa(vector<vector<char>>&mapa, vector<int>&pos){
    int x,y;
    for(int i=0;i<(int)llaves.size();i++)
    {
        x = llaves[i][0];
        y = llaves[i][1];
        if(mapa[pos[0]+x][pos[1]+y] == 'T') return true;
    }
    return false;
}


int gettingGold(vector<vector<char>>&mapa, vector<int>&inicio){
    int oro=0,x,y;
    vector<vector<bool>> visitados((int)mapa.size(),vector<bool>((int)mapa[0].size(),0));
    visitados[inicio[0]][inicio[1]] = 1;
    stack<vector<int>>pila;
    pila.push(inicio);
    while(!pila.empty())
    {
        vector<int>posActual = pila.top();
        pila.pop();
        if(mapa[posActual[0]][posActual[1]] == 'G') oro++;
        if(!hayTrampa(mapa,posActual))
        {
            for(int i=0;i<(int)llaves.size();i++){
                x = llaves[i][0];
                y = llaves[i][1];
                if(mapa[posActual[0]+x][posActual[1]+y] != '#' && !visitados[posActual[0]+x][posActual[1]+y])
                {
                    visitados[posActual[0]+x][posActual[1]+y] = 1;
                    pila.push({posActual[0]+x, posActual[1]+y});
                }
            }
        }
    }
    return oro;
}



int main(){
    int W,H;
    char letra;
    cin>>W>>H;
    vector<vector<char>>mapa(H, vector<char>(W,' '));
    vector<int>inicio;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>letra;
            if(letra == 'P')
            {
                inicio.push_back(i);
                inicio.push_back(j);
            }
            mapa[i][j] = letra;
        }
    }
    cout<<gettingGold(mapa,inicio)<<"\n";
    return 0;
}
