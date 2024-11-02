#include<iostream> //what? Wrong answer
using namespace std;
#include<algorithm>
#include<vector>
#define ulli unsigned long long int

int main(){
    ulli n,x,ans;
    cin>>n;
    vector<ulli>v;
    while(n--)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(ulli i=0;i<(ulli)v.size();i++)
    {
        ans = i;
        if(v[i]<i+1)
        {
            break;
        }
    }
    cout<<ans<<'\n';
    return 0;
}