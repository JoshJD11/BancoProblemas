#include<iostream> 
using namespace std;
#include<vector>
#define mod 1000000007


int memo[1000001];

void clean() {
    for(int i = 0; i < 1000001; i++) {
        memo[i] = -1;
    }
}


int dp(vector<int>&coins, int remaining) {
    if(remaining < 0) return 0;
    if(remaining == 0) return 1;
    if(memo[remaining] != -1) return memo[remaining];

    int ways = 0;
    for(int i = 0; i < (int)coins.size(); i++) {
        ways = (ways + dp(coins, remaining - coins[i]))%mod;
    }
    return memo[remaining] = ways;
}



int main () {

    cin.tie(0);
    ios::sync_with_stdio(false);

    clean();

    int n,x,coin;
    cin>>n>>x;
    vector<int> coins;

    while(n--) {
        cin>>coin;
        coins.push_back(coin);
    }

    cout<<dp(coins, x)<<'\n';

    return 0;
}