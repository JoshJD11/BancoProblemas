#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, ans = 0, lastEnd = 0;
    cin>>n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin>>start>>end;
        movies[i] = {end, start};
    } sort(movies.begin(), movies.end());

    for (auto &[end, start] : movies) {
        if (start >= lastEnd) {  
            ans++;
            lastEnd = end;
        }
    } cout<<ans<<'\n';
    return 0;
}
