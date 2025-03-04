#include <bits/stdc++.h>
using namespace std;

int main() {
    int numArticulos, indiceH = 0, maximo;
    cin>>numArticulos;

    vector<int> listaArticulos(numArticulos, 0);
    int indice = 0;
    while (indice < numArticulos) {
        cin>>listaArticulos[indice];
        indice++;
    }

    sort(listaArticulos.begin(), listaArticulos.end());

    indice = 1;
    while (indice <= numArticulos) {
        maximo = min(indice, listaArticulos[numArticulos - indice]);
        if (maximo > indiceH) indiceH = maximo;
        indice++;
    }

    cout << indiceH;
    return 0;
}
