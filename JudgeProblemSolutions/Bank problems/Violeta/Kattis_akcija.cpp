#include<iostream> //ACCEPTED
#include<algorithm>
using namespace std;
#include<vector>
#define ulli unsigned long long int


ulli Akcija(vector<int>&v)
{
    ulli sum = 0;
    int i=0;
    while(i+2 < (int)v.size())
    {
        sum+= v[i] + v[i+1];
        i+=3;
    }
    for(int j=i;j<(int)v.size();j++) sum+=v[j];
    return sum;
}



int main(){
    int n,x;
    vector<int>v;
    cin>>n;
    while(n--)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<Akcija(v)<<'\n';
    return 0;

}