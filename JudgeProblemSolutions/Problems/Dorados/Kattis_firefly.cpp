#include <bits/stdc++.h>
using namespace std;

int main() {
  int num_elementos, valor_maximo, valor_actual;
  cin>>num_elementos>>valor_maximo;

  vector<int> suma_izquierda(valor_maximo, 0), suma_derecha(valor_maximo, 0);

  int indice = 0;
  while (indice < num_elementos) {
    cin >> valor_actual;
    (indice % 2) ? suma_izquierda[valor_maximo - valor_actual]++ : suma_derecha[valor_actual - 1]++;
    indice++;
  }

  int suma_acumulada = 0;
  indice = valor_maximo - 1;
  while (indice >= 0) {
    suma_acumulada += suma_derecha[indice];
    suma_derecha[indice] = suma_acumulada;
    indice--;
  }

  suma_acumulada = 0;
  indice = 0;
  while (indice < valor_maximo) {
    suma_acumulada += suma_izquierda[indice];
    suma_izquierda[indice] = suma_acumulada;
    indice++;
  }

  int costo_minimo = INT_MAX, conteo_minimo = 0;
  indice = 0;
  while (indice < valor_maximo) {
    int suma_total = suma_izquierda[indice] + suma_derecha[indice];
    if (suma_total < costo_minimo) {
      costo_minimo = suma_total;
      conteo_minimo = 0;
    }
    if (suma_total == costo_minimo) conteo_minimo++;
    indice++;
  }

  cout << costo_minimo << " " << conteo_minimo << endl;
}
