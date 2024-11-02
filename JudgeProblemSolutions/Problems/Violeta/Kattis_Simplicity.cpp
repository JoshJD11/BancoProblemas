#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#include<algorithm>

int memo[26];


void clean(){for(int i=0;i<26;i++) memo[i] = 0;}


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int cast,cantDifferent=0,ans=0;
    string word;
    cin>>word;
    vector<int>v;
    clean();
    for(int k=0;k<(int)word.size();k++)
    {
        cast = static_cast<int>(word[k])%97;
        if(memo[cast]==0){cantDifferent++;}
        memo[cast]++;
    }
    if(cantDifferent <= 2){cout<<0;}
    else{
        for(int i=0;i<26;i++){
            if(memo[i]!=0) v.push_back(memo[i]);
        }

        sort(v.begin(),v.end());

        for(int j=0;j<(int)v.size();j++){
            ans+=v[j];
            cantDifferent--;
            if(cantDifferent <=2){
                cout<<ans;
                break;
            }
        }
    }
    cout<<"\n";
    return 0;
}
