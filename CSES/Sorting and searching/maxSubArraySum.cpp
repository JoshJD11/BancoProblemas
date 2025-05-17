#include<iostream>
using namespace std;
#include<vector>
#define lli long long int

int main() {
    lli n, maxInt = -(1LL<<(30));
    cin>>n;
    vector<lli>v;
    bool flag = false;
    while(n--) {
        lli x;
        cin>>x;
        maxInt = max(maxInt, x);
        if(x>=0) flag = true;
        v.push_back(x);
    } lli actual = 0, global = 0; 
    if(!flag) {
        cout<<maxInt<<'\n';
    } else {
        for(lli i = 0; i < (lli)v.size(); i++) {
            if(actual + v[i] < 0) actual = 0;
            else {
                actual += v[i];
                global = max(global, actual);
            }
        } cout<<global<<'\n';
    }
    return 0;
}