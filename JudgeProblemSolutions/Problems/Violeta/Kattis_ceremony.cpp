#include <iostream> //Wrong answer
using namespace std;
#include<map>
#include<algorithm>
#include<vector>


int cantSteps(vector<int>towers, vector<int> copy, map<int,int>& cantTowersOfHeight) {
    int steps = 0, actualHeight, actualCopyHeight, canEliminate, cantZero = 0;
    for(int i = 0; i < (int)towers.size(); i++) {
        if(copy[i] != 0) {
            actualHeight = towers[i];
            canEliminate = cantTowersOfHeight[actualHeight];
            actualCopyHeight = copy[i];
            if(canEliminate >= actualCopyHeight) {
                for(int j=i;j<(int)copy.size();j++) {
                    copy[j] -= actualCopyHeight; 
                }
                steps+=actualCopyHeight;
            }
            else steps ++;
        }

    }
    return steps;
}


int main() {
   int n,x;
   cin>>n;
    vector<int>towers;
    map<int,int>cantTowersOfHeight;
    while(n--){
        cin>>x;
        towers.push_back(x);
        cantTowersOfHeight[x]++;
    }
    sort(towers.begin(),towers.end());
    cout<<cantSteps(towers,towers,cantTowersOfHeight)<<'\n';
    return 0;
}
