#include<iostream> //ACCEPTED
using namespace std;
#define INS 1
#define DEL 0
#define MISSMATCH 1
#define MATCH 0


int memo[55][30];
int vis[55][30];


int A(string& word, string& alphabet, int i, int j)
{
    if(i < 0) return INS*(j+1);
    if(j < 0) return DEL*(i+1);
    if(vis[i][j]) return memo[i][j];
    vis[i][j] = 1;
    return memo[i][j] = min(((word[i] == alphabet[j])? MATCH:MISSMATCH) + A(word,alphabet,i-1,j-1), min(INS + A(word,alphabet,i,j-1), DEL + A(word,alphabet,i-1,j)));

}


int main()
{
    string word,alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin>>word;
    cout<<A(word,alphabet,word.size()-1,alphabet.size()-1)<<'\n';
    return 0;
}

//"abcdefghijklmnopqrstuvwxyz"
//"xyzabcdefghijklmnopqrstuvw"  --  3
//"aiemckgobjfndlhp"  --  20