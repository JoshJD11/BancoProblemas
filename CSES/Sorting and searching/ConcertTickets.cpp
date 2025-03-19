#include<iostream>
using namespace std;
#include<set>



int main() {

    int n,m,x;
    cin>>n>>m;
    multiset<int>tickets;
    
    while(n--) {
        cin>>x;
        tickets.insert(x);
    }

    while(m--) {
        cin>>x;
        if(!tickets.empty()) {
            auto it = tickets.lower_bound(x);
            if(it != tickets.end()){
                if(*it == x) {
                    cout<<x<<'\n';
                    tickets.erase(it);
                } else {
                    if(it != tickets.begin()) {
                        it--;
                        cout<<*it<<'\n';
                        tickets.erase(it);
                    } else cout<<-1<<'\n';
                }
            } else {
                auto greatest = *tickets.rbegin();
                cout<<greatest<<'\n';
                tickets.erase(--tickets.end());
            }
        } else cout<<-1<<'\n';
    }

    return 0;
}