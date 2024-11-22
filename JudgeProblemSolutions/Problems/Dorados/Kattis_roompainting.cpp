#include <bits/stdc++.h>
using namespace std;

int main() {
    int cantidadPinturas, cantidadConsultas, tamanioPintura, consulta, indice;
    cin>>cantidadPinturas>>cantidadConsultas;

    vector<int> pinturas;
    while (cantidadPinturas--) {
        cin>>tamanioPintura;
        pinturas.push_back(tamanioPintura);
    }

    sort(pinturas.begin(), pinturas.end());

    long long int desperdicio = 0;
    while (cantidadConsultas--) {
        indice = 0;
        cin>>consulta;
        while (pinturas[indice] < consulta) {
            indice++;
        }
        desperdicio += pinturas[indice] - consulta;
    }

    cout<<desperdicio; //porque dice que imprima una sola linea, si no, no lo acepta
    return 0;
}
