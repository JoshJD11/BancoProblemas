#include<iostream>
using namespace std; //ACCEPTED
#include<algorithm>
#include<vector>


int main() {
    int n,a,x;
    cin>>n>>a;
    vector<int>v;
    while(n--) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<(int)v.size();i++) {
        if(a > v[i]) {
            ans++;
            a -= (v[i] + 1);
        }
        else break;
    }
    cout<<ans<<'\n';
    return 0;
}
