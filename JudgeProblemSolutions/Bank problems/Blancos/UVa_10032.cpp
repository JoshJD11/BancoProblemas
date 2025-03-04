#include <bits/stdc++.h> //NO saleeeeeee
using namespace std;


struct elemento {
    int pesoA;
    int pesoB;
    int cantA;
    int cantB;
    vector<int>pesos;
};


struct ComparadorDiferencia {
    bool operator()(const elemento& e1, const elemento& e2) {
        int diff1 = abs(e1.pesoA - e1.pesoB);
        int diff2 = abs(e2.pesoA - e2.pesoB);
        return diff1 > diff2;
    }
};


void trackBacking(vector<int>& pesos) {
    priority_queue<elemento, vector<elemento>, ComparadorDiferencia> cola;
    elemento inicializador = {0, 0, 0, 0, pesos};
    cola.push(inicializador);
    while(!cola.empty()) {
        elemento actual = cola.top();
        cola.pop();

        if(actual.pesos.empty()){

            cout<<min(actual.pesoA, actual.pesoB)<<" "<<max(actual.pesoA,actual.pesoB)<<'\n';
            return ;
        }

        for(int i=0;i<actual.pesos.size();i++) {
            int pesoActual = actual.pesos[i];
            vector<int> copia;

            for(int j=0;j<actual.pesos.size();j++){
                if(i != j) copia.push_back(actual.pesos[j]);
            }
            if(actual.cantA == actual.cantB){
                cola.push({actual.pesoA + pesoActual, actual.pesoB, actual.cantA+1, actual.cantB, copia});
                cola.push({actual.pesoA, actual.pesoB + pesoActual, actual.cantA, actual.cantB+1, copia});
            }
            if(actual.cantA > actual.cantB){
                cola.push({actual.pesoA, actual.pesoB + pesoActual, actual.cantA, actual.cantB+1, copia});
            }
            else{
                cola.push({actual.pesoA + pesoActual, actual.pesoB, actual.cantA+1, actual.cantB, copia});
            }
        }
    }
}



int main(){
    int T, people, peso;
    cin>>T;
    while(T--) {
        cin>>people;
        vector<int> pesos;
        while(people--) {
            cin>>peso;
            pesos.push_back(peso);
        }
        trackBacking(pesos);
        if(T)cout<<'\n';
    }
    return 0;
}



// .\programa.exe
// g++ UVa_10032.cpp -o programa.exe
