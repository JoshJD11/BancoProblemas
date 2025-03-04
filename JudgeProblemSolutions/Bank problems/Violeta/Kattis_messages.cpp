#include<iostream> //ACCEPTED!
using namespace std;
#include<vector>
#include<algorithm>


int maxLaundry(vector<int>&v, int C, int K)
{
    int laundry = 1,count=C-1;

    for(int i=0;i<(int)v.size()-1;i++)
    {
        if(count == 0 || (v[i+1] - v[i] > K))
        {
            laundry++;
            count = C-1;
        }
        else {
            count--;
        }
    }
    return laundry;
}


int main(){
    int S,C,K,X;
    cin>>S>>C>>K;
    vector<int>v;
    while(S--)
    {
        cin>>X;
        v.push_back(X);
    }
    sort(v.begin(),v.end());
    cout<<maxLaundry(v,C,K)<<'\n';
    return 0;
}