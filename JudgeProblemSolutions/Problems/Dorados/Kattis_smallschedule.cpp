#include<iostream> //me ganó un corner case
using namespace std;


int main(){
    int Q,M,S,L,suma;
    cin>>Q>>M>>S>>L;
    suma = (L/M) * Q + S/M;
    L = L%M;
    S = S%M;
    if(!L && !S) cout<<suma<<'\n';
    else if(!L) cout<<suma+1<<'\n';
    else if(M-S < L)
    {
        int cantUnos = S/(M-L);
        if(S%(M-L) != 0) cantUnos++;
        cout<<min(suma + Q + 1, suma + cantUnos)<<'\n';
    }
    else cout<<suma + Q<<'\n';
}