#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#define ulli long long int


ulli memo[5][30001];
char visited[5][30001];


ulli countWays(vector<char>&v, short num, short i)
{
    if(num<0) return 0;
    if(num == 0 || v[i] == 1) return 1;
    if(visited[i][num]) return memo[i][num];
    visited[i][num] = 1;
    return memo[i][num] = countWays(v,num-v[i],i) + countWays(v,num,i+1);
    
}

int main()
{
    short n;
    vector<char>v = {50,25,10,5,1};
    while(cin>>n)
    {
        ulli ans = countWays(v,n,0);
        if(ans == 1) cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}