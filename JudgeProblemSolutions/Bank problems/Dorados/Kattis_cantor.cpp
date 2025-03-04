#include <iostream>
#include <string>
using namespace std;


bool decimalABase3(double decimal, int precision = 10) {
    string resultado = "0.";
    for (int iteracion = 0; iteracion < precision; iteracion++) {
        decimal *= 3;
        int parteEntera = static_cast<int>(decimal);
        if (parteEntera == 1) {
            return false;
        }
        resultado += to_string(parteEntera);
        decimal -= parteEntera;
        if (decimal == 0) {
            break;
        }
    }
    return true;
}

int main() {
    string entrada;
    cin>>entrada;

    while (entrada != "END") {
        double numero = stod(entrada);
        if (decimalABase3(numero, 10)) {
            cout<<"MEMBER"<<endl;
        } else {
            cout<<"NON-MEMBER"<<endl;
        }
        cin>>entrada;
    }

    return 0;
}
