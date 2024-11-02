#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int f(int a)
{
    return (a<0)? -a:a;
}


bool isGay(vector<int>&v)
{
    sort(v.begin(),v.end());
    int diff = f(v[1] - v[0]);
    for(int i=2; i<(int)v.size();i++)
    {
        if(v[i] - v[i-1] != diff) return false;
    }
    return true;
}


int main()
{
    int n,m,x,diff;
    bool flag;
    cin>>n;
    while(n--)
    {
        vector<int>v;
        cin>>m;
        flag = false;
        for (int i=0;i<m;i++)
        {

            cin>>x;
            v.push_back(x);
            if(i==1)
            {
                diff = f(v[i] - v[i-1]);
            }
            if(i>=2 && !flag)
            {
                if(f(v[i] - v[i-1]) != diff) flag = true;
            }
        }
        if(!flag) cout<<"arithmetic\n";
        else if(isGay(v))
        {
            cout<<"permuted arithmetic\n";
        }
        else cout<<"non-arithmetic\n";

    }
    return 0;
}
