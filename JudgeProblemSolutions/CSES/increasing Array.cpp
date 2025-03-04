#include<iostream>
using namespace std;
#define ulli unsigned long long int


ulli absoluteValue(ulli a) {
    return (a<0)? -a:a;
}


int main() {
    ulli n, m, last, count = 0;
    cin>>n;
    n--;
    cin>>last;
    while(n--) {
        cin>>m;
        if(m < last) count += absoluteValue(last-m);
        else last = m;

    }
    cout<<count<<"\n";
    return 0;
}