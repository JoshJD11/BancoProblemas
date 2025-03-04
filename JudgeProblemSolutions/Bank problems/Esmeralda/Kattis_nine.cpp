#include<iostream>
using namespace std;
#define ull unsigned long long int
#define mod 1000000007

ull elevar(ull e)
{
    if(e==0) return 1;
    ull r = elevar(e/2);
    r = (r * r)%mod;
    if(e%2) r = (r * 9)%mod;
    return r;
}

int main(){
    short int T;
    ull d;
    cin>>T;

    while(T--)
    {
        cin>>d;
        cout<<(8*elevar(d-1))%mod<<'\n';
    }

    return 0;
}