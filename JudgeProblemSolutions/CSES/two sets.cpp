#include <iostream>
using namespace std;
#define ulli unsigned long long int
#include <vector>


ulli gauss(ulli n) {
    return (n*(n+1))/2;
}



void solve(ulli n, ulli target) {

    vector<ulli> set1;
    ulli source = target;

    for(ulli i = n; i >= 1; i--) {
        if(source <= i) {
            set1.push_back(source);
            break;
        }
        source -= i;
        set1.push_back(i);
    }

    ulli size = set1.size();
    cout<<size<<"\n";

    for(ulli i = 0; i < size; i++) cout<<set1[i]<<" ";

    cout<<'\n'<<n - size<<'\n';
    ulli lastIndex = size - 1;

    for(ulli i = 1; i <= n; i++) {
        if(lastIndex >= 0) {
            if(i == set1[lastIndex]) {
                lastIndex --;
            } else{
                cout<<i<<" ";
            }
        } else {
            cout<<i<<" ";
        }
    }
    cout<<'\n';

}


int main() {
    ulli n;
    cin>>n;

    ulli m = gauss(n);

    if(m % 2) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
        solve(n, m/2);
    }

    return 0;
}