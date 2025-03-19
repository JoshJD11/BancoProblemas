#include<iostream>
using namespace std;
#define ulli unsigned long long int

int main() { 
    ulli t;
    cin>>t;
    while(t--) {
        ulli x,y;
        cin>>x>>y;

        if(x > y) {

            (x%2)? cout<<(x-1) * (x-1) + y : cout<<(x-1) * (x-1) + 2*x - y;

        } else if(y > x) {

            (y%2)? cout<<(y-1) * (y-1) + 2*y - x : cout<<(y-1) * (y-1) + x;

        } else {
            cout<<x*x - (x-1);
        } 
        cout<<'\n';
    }
    return 0;
}