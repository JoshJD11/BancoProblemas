#include<iostream> //ACCEPTED
using namespace std;
#include<vector>

int memo[1001][6001];

void clean(int filas, int columnas){
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            memo[i][j] = -2;
}

int dp(vector<int>&pesos, vector<int>&capacidades, int capacidad, int i){
    if(capacidad<0) return -1;
    if(i == (int)pesos.size()) return 0;
    if(memo[i][capacidad] != -2) return memo[i][capacidad];
    return  memo[i][capacidad] = max(dp(pesos,capacidades,capacidad, i+1), 
    1 + dp(pesos,capacidades, min(capacidades[i], capacidad - pesos[i]), i+1));
}


int main(){
    int N;
    while (cin>>N && N)
    {
        clean(N,6001);
        vector<int>pesos(N,0);
        vector<int>capacidades(N,0);
        for(int i=0;i<N;i++){
            cin>>pesos[i];
            cin>>capacidades[i];
        }
        cout<<dp(pesos,capacidades,6001,0)<<'\n';
    }
    
    return 0;
}