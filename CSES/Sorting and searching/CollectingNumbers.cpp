#include<iostream> 
using namespace std;
#define ulli unsigned long long int



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ulli n,x;
    cin>>n;
    ulli nums[n+1];

    for(ulli i = 0; i < n; i++) { 
        cin>>x;
        nums[x] = i;
    } 

    ulli ans = 1;
    for(ulli j = 2; j <= n; j++) {
        if(nums[j] < nums[j-1]) ans++;
    }

    cout<<ans<<'\n';

    return 0;
}
