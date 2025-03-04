#include<iostream> //accepted
using namespace std;
#include<vector>
#include<algorithm>


int froshWeek(vector<int>&tasks, vector<int>&silences) {
    int ans = 0, index = 0;
    for(int i=0;i<(int)silences.size();i++) {
        if(index == (int)tasks.size()) break;
        for(int j=index;j<(int)tasks.size();j++) {
            if(tasks[j] <= silences[i]) {
                index = j+1;
                ans++;
                break;
            }
        }
    }
    return ans;
}



int main(){
    int n,m,x;
    cin>>n>>m;
    vector<int>tasks;
    vector<int>silences;

    while(n--) {
        cin>>x;
        tasks.push_back(x);
    }
    while(m--) {
        cin>>x;
        silences.push_back(x);
    }

    sort(tasks.begin(),tasks.end());
    sort(silences.begin(),silences.end());

    cout<<froshWeek(tasks,silences)<<'\n';

    return 0;
}
