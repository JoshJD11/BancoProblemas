#include<iostream>
using namespace std;


int main() {
    int n;
    cin>>n;

    if(n == 2 || n == 3) {
        cout<<"NO SOLUTION\n";
    } else {

        for(int i = 2; i <= n; i+=2) cout<<i<<" ";

        for(int i = 1; i <= n; i+=2) (i + 2 > n)? cout<<i<<"\n" : cout<<i<<" ";

    }


    return 0;
}