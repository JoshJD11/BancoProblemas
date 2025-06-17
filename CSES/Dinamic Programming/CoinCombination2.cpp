#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin>>coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1; 

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    cout<<dp[x]<<'\n';
    return 0;
}


/*

13 92342
1 2 3 4 67340 67335 67330 67329 67322 67321 67320 67319 67318

*/