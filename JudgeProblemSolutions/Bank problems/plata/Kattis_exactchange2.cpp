#include<iostream> //ACCEPTED!!!!
using namespace std;
#include<vector>

vector<int> memo[105][10005];



void clean(int cant, int doubt)
{
    for(int i=0;i<cant+3;i++)
        for(int j=0;j<doubt+3;j++) 
        {
            memo[i][j] = {};
        }
}


vector<int> minimo(vector<int>v1, vector<int>v2, int num)
{
    v1[0]+=num;
    v1[1]++;
    if(v1[0]<v2[0]) return v1;
    if(v1[0] == v2[0]) return {v1[0], min(v1[1],v2[1])};
    return v2;
}


vector<int> minMoney(vector<int>&v, int doubt, int index)
{
    if(doubt<=0) return {0,0};
    if(index==(int)v.size()) return {1<<(25),0};
    if(!memo[index][doubt].empty()) return memo[index][doubt];
    return memo[index][doubt] = minimo(minMoney(v,doubt-v[index],index+1),minMoney(v,doubt,index+1), v[index]);

}


int main()
{
    int T,doubt,cant,x;
    cin>>T;
    while(T--)
    {
        cin>>doubt>>cant;
        vector<int>v;
        while(cant--)
        {
            cin>>x;
            v.push_back(x);
        }
        clean(v.size(),doubt);
        vector<int>ans = minMoney(v,doubt,0);
        cout<<ans[0]<<" "<<ans[1]<<'\n';
    }

}