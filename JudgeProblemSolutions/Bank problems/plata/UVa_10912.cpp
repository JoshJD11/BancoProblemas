#include<iostream> //ACCEPTED!
using namespace std;


int memo[26][10000][142]; 


int parseChar(char letter){
    return static_cast<int>(letter)%97 + 1;
}


void prepareMemo(){
    for(int i=0;i<26;i++){
       for(int j=0;j<10000;j++){
            for(int k=0;k<142;k++){
                memo[i][j][k] = -1;
            }
       } 
    }
}


int dp(const string& alphabet, int capacity, int length, int index){
    if(capacity == 0 && length == 0) return 1;
    if(capacity < 0 || length < 0 || index == (int)alphabet.length()) return 0;
    if(memo[index][capacity][length] != -1) return memo[index][capacity][length];
    return memo[index][capacity][length] = dp(alphabet,capacity,length,index+1) + dp(alphabet,capacity-parseChar(alphabet[index]),length-1,index+1);
}


int main(){
    int L,S,caseNum = 0;
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    prepareMemo();
    while(cin>>L>>S && L && S)
    {
        caseNum++;
        cout<<"Case "<<caseNum<<": "<<((L*(L+1)/2 > S)? 0 : dp(alphabet,S,L,0))<<'\n';
    }
    return 0;
}

//g++ -o UVa_10912 UVa_10912.cpp
// ./UVa_10912