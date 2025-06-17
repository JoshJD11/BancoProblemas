#include<iostream>
using namespace std;
#include<vector>
#define oo 1000001
 
 
int memo[1000001];

 
int dp(vector<int>&coins, int x) {
    if(x < 0) return oo;
    if(x == 0) return 0;
    if(memo[x]) return memo[x];

    int minCoins = oo;
    for(int i = 0; i < (int)coins.size(); i++) {
        minCoins = min(minCoins, 1 + dp(coins, x - coins[i]));
    }
    return memo[x] = minCoins;
}
 
 
int main() {
    int n,x,coin;
    cin>>n>>x;
    vector<int>coins;
 
    while(n--) {
        cin>>coin;
        coins.push_back(coin);
    }

    int result = dp(coins, x);
    cout<<(result == oo? -1 : result)<<'\n';
 
    return 0;
}