#include<iostream>
using namespace std;


int main() {
    int t;
    cin>>t;

    while(t--) {

        int a,b;
        cin>>a>>b;

        int maxi = max(a,b), mini = min(a,b);
        if(maxi - 2 * mini <= 0 && ((a + b) % 3) == 0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }

    }

    return 0;
}