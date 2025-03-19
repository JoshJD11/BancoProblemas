#include<iostream>
using namespace std;


int main() {
    string s;
    cin>>s;

    int ans = 0, counter = 0;
    char current = s[0];

    for(int i=0; i<(int)s.size(); i++) {
        if(s[i] != current) {
            current = s[i];
            ans = max(ans, counter);
            counter = 1;
        }
        else {
            counter ++;
        }
        if(i == s.size() - 1) {
            ans = max(ans, counter);
        }
    }

        cout<<ans<<"\n";

    return 0;
}