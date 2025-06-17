#include<iostream>
using namespace std;
#define mod 1000000007


int memo[1000001];


int dp(int remaining) {
    if(remaining < 0) return 0;
    if(remaining == 0) return 1;
    if(memo[remaining]) return memo[remaining];

    int sum = 0;
    for(int i = 1; i < 7; i++) {
        sum = (sum + dp(remaining - i))%mod;
    } 
    return memo[remaining] = sum;
}


int main() {
    int n;
    cin>>n;
    cout<<dp(n)<<'\n';
    return 0;
}

