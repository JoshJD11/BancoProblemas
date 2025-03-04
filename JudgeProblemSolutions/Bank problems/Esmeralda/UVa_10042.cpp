#include<iostream>
using namespace std;
#include<vector>
#define ulli unsigned long long int


ulli sumDigits(ulli num)
{
    ulli sum = 0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}


ulli sumFactorsDigits(vector<ulli>&v)
{
    ulli sum = 0;
    for(int i=0;i<(int)v.size();i++)
    {
      sum+=sumDigits(v[i]);  
    }
    return sum;
}


void getFactors(vector<ulli>&v, ulli n)
{
    ulli i = 2;
    while(n!=1 && i*i<=n)
    {
        while(n%i==0)
        {
           v.push_back(i); 
           n/=i;
        }   
        i++;
    }
    if(n!=1) v.push_back(n);
}


int main(){
    unsigned int n,T;
    ulli i;
    cin>>T;
    while(T--)
    {
        cin>>n;
        i = n+1;
        while(1)
        {
            vector<ulli>v;
            getFactors(v,i);
            if(sumDigits(i) == sumFactorsDigits(v) && (int)v.size() > 1) break;
            i++;
        }
        cout<<i<<'\n';
    }
    return 0;
}