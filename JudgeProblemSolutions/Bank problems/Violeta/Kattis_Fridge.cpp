#include<iostream> //ACCEPTED
using namespace std;
#include<vector>


void printNum(int n, int cantVeces){
    for(int i=0;i<cantVeces;i++) cout<<n;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> memo;
    memo.resize(10);
    char letter;
    int cont=0;
    while(cin>>letter && letter!='!') {memo[static_cast<int>(letter)%48]++; cont++;}
    if(cont==1){
        if(letter == '1') cout<<2;
        else cout<<1;
    }
    else{
        int menor=1<<(25),index,SegundoMenor=1<<(25),segundoIndex;
        for(int i=0;i<10;i++){
            if(memo[i]<menor){
                menor = memo[i];
                index = i;
            }
        }
        for(int j=0;j<10;j++){
            if(memo[j]<SegundoMenor && j!=index){
                SegundoMenor = memo[j];
                segundoIndex = j;
            }
        }
        if(index != 0){
            printNum(index,menor+1);
        }
        else{
            if(menor == SegundoMenor){
                printNum(segundoIndex,SegundoMenor+1);
            }
            else{
                printNum(segundoIndex,1);
                printNum(index,menor+1);
            }
        }
    }
    cout<<'\n';
}