#include<iostream>
#include <bitset>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++) {
        int gray = i ^ (i >> 1); 
        int start = 100 - n;  
        bitset<100> bs(gray);  
        for(int j = start; j < 100; j++) {
            cout << bs[99 - j]; 
        }
        cout << '\n';  
    }
    return 0;
}
