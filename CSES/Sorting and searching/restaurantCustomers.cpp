#include<iostream> //algoritmo sweep line (barrido de eventos)
using namespace std;
#include<vector>
#include<algorithm>


struct {
    bool operator()(vector<int>& a, vector<int>& b) const {
        return a[0] < b[0];
    }
} customSort;


int main() {
    int n, x, y, ans = 0, count = 0;
    cin>>n;
    vector<vector<int>> v;
    while(n--) {
        cin>>x>>y;
        v.push_back({x,1});
        v.push_back({y,-1});
    }   sort(v.begin(), v.end(), customSort); 

    for(int i = 0; i < v.size(); i++) {
        count+=v[i][1];
        ans = max(ans, count);
    } cout<<ans<<'\n';
    return 0;
}
