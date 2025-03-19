#include<iostream>
using namespace std;


void hanoi(int n, int o, int a, int d) {
    if(n == 1) {
        cout<<o<<" "<<d<<'\n';
    } else {
        hanoi(n-1, o, d, a);
        cout<<o<<" "<<d<<'\n';
        hanoi(n-1, a, o, d);
    }
}


int main() {
    int n;
    cin>>n;

    cout<<((1<<n) - 1)<<'\n';
    hanoi(n, 1, 2, 3);

    return 0;
}