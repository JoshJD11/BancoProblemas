#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define ulli unsigned long long int


int main () {
    ulli n, x, t;
    cin>>n>>x;
    vector<vector<ulli>>v;
    for(ulli k = 0; k < n; k++) {
        cin>>t;
        v.push_back({t, k + 1});
    } sort(v.begin(),v.end());
    ulli i = 0, j = v.size()-1;
    while(i!=j) {
        ulli sum = v[i][0] + v[j][0];
        if(sum == x) {
            cout<<v[i][1]<<" "<<v[j][1]<<'\n';
            break;
        } if(sum > x) j--;
        else i++;
    } if(i == j) cout<<"IMPOSSIBLE\n";
    return 0;
}