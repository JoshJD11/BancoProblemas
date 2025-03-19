#include <iostream>
using namespace std;
#define ull unsigned long long int


void weirdAlgorithm(ull n) {
    if(n == 1) {
        return ;
    }
    if(n%2) {
        cout<<3*n+1<<" ";
        weirdAlgorithm(3*n+1);
    }
    else {
        cout<<n/2<<" ";
        weirdAlgorithm(n/2);
    }
}


int main() {
    ull n;
    cin>>n;
    cout<<n<<" ";
    weirdAlgorithm(n);
    return 0;
}