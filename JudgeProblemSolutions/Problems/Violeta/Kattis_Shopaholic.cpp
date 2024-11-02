#include<iostream> //ACCEPTED
#include<algorithm>
using namespace std;
#include<vector>
#define ulli unsigned long long int


ulli Shopaholic(vector<int>&v)
{
    ulli sum = 0;
    int i=0,n1,n2,n3;
    while(i+2 < (int)v.size())
    {
        n1 = v[i];
        n2 = v[i+1];
        n3 = v[i+2];
        sum+= min(n1,min(n2,n3));
        i+=3;
    }
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
    cout<<Shopaholic(v)<<'\n';
    return 0;

}
