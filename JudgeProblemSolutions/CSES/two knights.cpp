#include <iostream>
using namespace std;
#define ulli unsigned long long int


ulli gauss(ulli n) {
    return (n*(n+1))/2;
}


int main() {
    ulli n, c;
    cin>>n;
    for(ulli i = 1; i <= n; i++) {
        c = gauss(i * i - 1);
        if(i == 1 || i == 2) {
            cout<<c<<'\n';
        } else {
            ulli a = gauss(i - 2) * 8;
            cout<<c - a<<"\n";
        }
    }
    return 0;
}