#include<iostream>
using namespace std;
#include<map>


string ans = "";


string reverse(string& s) {
    string ans = "";
    for(int i = s.size()-1; i>=0; i--) {
        ans += s[i];
    }
    return ans;
}


void concatenateChars(char letter, int times) {
    while(times--) ans += letter;
}


void solve(map<char,int>& letterMap) {
    char oddChar = '!'; int times = 0;

    for(const auto& par : letterMap) {

        char letter = par.first; int cant = par.second;


        if(cant % 2) {
            oddChar = letter;
            times = cant;
        } else {
            concatenateChars(letter, cant/2);
        }
    }
    string reversedString = reverse(ans);
    concatenateChars(oddChar, times);
    cout<<ans + reversedString<<'\n';
}


int main() {
    string s;
    cin>>s;
    map<char, int> letters;
    int cantOdd = 0;

    for(int i=0;i<s.size();i++) {
        letters[s[i]]++;
        if(letters[s[i]] % 2) {
            cantOdd++;
        } else {
            cantOdd--;
        }
    }
     
    if(cantOdd > 1) {
        cout<<"NO SOLUTION\n";
    } else {
        solve(letters);
    }
    

    return 0;
}