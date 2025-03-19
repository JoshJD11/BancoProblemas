#include <iostream>
using namespace std;
#define ull unsigned long long int


int main() {
    ull n; 
    cin>>n;
    ull sum = 0;
    for(int i=0; i<n-1; i++) {
        ull m;
        cin>>m;
        sum+=m;
    }
    cout<<((n*(n+1))/2) - sum <<"\n"; 
    return 0;
}