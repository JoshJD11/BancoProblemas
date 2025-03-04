#include<iostream>
using namespace std;
#define ulli unsigned long long int

int main() {
    ulli n;
    cin>>n;

    ulli answer = 0;
    ulli pot5 = 1;

    for(ulli i = 1; pot5 <= n; i++ ) 
    {
        pot5 *= 5;
        answer += n/pot5;
    }

    cout<<answer<<'\n';


    return 0;
}