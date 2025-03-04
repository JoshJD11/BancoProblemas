#include <bits/stdc++.h>
using namespace std;

int main() {
    int cantidadTareas, numCompus, sobrantes, limite;
    cin>>cantidadTareas>>numCompus>>sobrantes>>limite;

    vector<int> cargaCompus(numCompus, 0);
    int indice = 0;
    while (indice < limite) {
        cargaCompus[indice % numCompus] += cantidadTareas;
        indice++;
    }

    sort(cargaCompus.begin(), cargaCompus.end());

    indice = 0;
    while ((indice < numCompus) && sobrantes) {
        while ((cargaCompus[indice] < cargaCompus[numCompus - 1]) && sobrantes) {
            cargaCompus[indice]++;
            sobrantes--;
        }
        indice++;
    }

    if (sobrantes) {
        indice = 0;
        while (sobrantes) {
            cargaCompus[indice % numCompus]++;
            sobrantes--;
            indice++;
        }
        sort(cargaCompus.begin(), cargaCompus.end());
    }

    cout<<cargaCompus[numCompus - 1];
    return 0;
}
