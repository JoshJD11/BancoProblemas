#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int k;


int binarySearch(vector<int>&v, int num, int inf) {
    int sup = (int)v.size()-1;
    while(inf < sup) {
        int m = (inf+sup)/2;
        if(v[m] < num - k) inf = m + 1;
        else sup = m;
    } return (inf < (int)v.size() && v[inf] <= num + k && v[inf] >= num - k)? inf:-1;

}


int main() {

    int n,m,x,ans=0, actual = 0;
    cin>>n>>m>>k;
    vector<int> people, apartments;
    while(n--) {
        cin>>x;
        people.push_back(x);
    } while(m--) {
        cin>>x;
        apartments.push_back(x);
    }
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    for(int i=0; i<(int)people.size(); i++) {
        int index = binarySearch(apartments, people[i], actual);
        if(index != -1) {
            ans++;
            actual = index + 1;
        }
    }

    cout<<ans<<'\n';


    return 0;
}

