#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define ulli unsigned long long int

int main() {

    ulli n,x;
    cin>>n;
    vector<ulli>v;

    while(n--) {
        cin>>x;
        v.push_back(x);
    } 
    
    sort(v.begin(), v.end());
    for(ulli i = 1; i<(ulli)v.size(); i++) v[i] += v[i-1];
    
    ulli target = 1, index = 0;

    while(index <= (ulli)v.size() - 1) {

        ulli acum = v[index];

        if (acum >= target) {
            ulli difference = acum - target;
            if(!(difference < target)) break;
            target += difference + 1;
        } 
        else index++;
    }
    
    cout<<target<<'\n';

    return 0;
}
