#include<iostream>
using namespace std;
#include<map>


int main() {
    int n,x,ans = 0;
    cin>>n;
    map<int,bool>myMap;
    while(n--) {
        cin>>x;
        if(!myMap[x]) {
            ans++;
            myMap[x] = 1;
        }
    }
    cout<<ans<<'\n';

    return 0;
}