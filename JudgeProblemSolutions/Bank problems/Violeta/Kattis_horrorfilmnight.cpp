#include<iostream> //wrongAnswer 
using namespace std;
#include<algorithm>
#include<vector>


int solve(vector<int>&Joshua, vector<int>&Adrian) {
    int cantDays = 0, indexJosh = 0, indexAdri = 0, cantJosh = 0, cantAdri = 0;
    bool unexpectedException = false;
    while(indexJosh != (int)Joshua.size() && indexAdri != (int)Adrian.size()) {
        if(Joshua[indexJosh] == Adrian[indexAdri]) {
            indexJosh++;
            indexAdri++;
            cantJosh = 0;
            cantAdri = 0; 
        }
        else if(Joshua[indexJosh] < Adrian[indexAdri]) {
            indexJosh++;
            cantJosh++;
        } else {
            indexAdri++;
            cantAdri++;
        }
        if(abs(cantJosh - cantAdri) < 2) {
            cantDays++;
        }
        else {
            unexpectedException = true;
            break;
        }
    }
    if((int)Joshua.size() != indexJosh && cantJosh <= cantAdri && !unexpectedException) {
        if (indexJosh + 1 != (int)Joshua.size()) cantDays += (abs(cantJosh - cantAdri) == 1)? 2:1;
        else cantDays+=1;
    }
    if((int)Adrian.size() != indexAdri && cantAdri <= cantJosh && !unexpectedException) {
        if (indexAdri + 1 != (int)Adrian.size()) cantDays += (abs(cantJosh - cantAdri) == 1)? 2:1;
        else cantDays+=1;
    }
    return cantDays;
}


int main() {
    int k,x;

    vector<int>Joshua;
    vector<int>Adrian;

    cin>>k;

    while(k--) {
        cin>>x;
        Joshua.push_back(x);
    }

    cin>>k;

    while(k--) {
        cin>>x;
        Adrian.push_back(x);
    }

    sort(Joshua.begin(),Joshua.end());
    sort(Adrian.begin(),Adrian.end());
    cout<<solve(Joshua,Adrian)<<'\n';
    return 0;
}