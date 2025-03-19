#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

int main() {
    int n,x,weight;
    cin>>n>>x;
    vector<int>children;
    while(n--) {
        cin>>weight;
        children.push_back(weight);
    } sort(children.begin(), children.end());

    int i = 0, j = children.size()-1, ans = 0;

    while(true) {
        if(i >= j) {
            if(i == j) ans++;
            break;
        } if(x - (children[i] + children[j]) >= 0) {
            i++;
            j--;
        } else {
            j--;
        } ans++;
    } cout<<ans<<'\n';
    return 0;
}