#include <iostream>
using namespace std;

int main(){
    int s,p,y,j,spotAge,puffAge,yertleAge;
    const short int d = 12;
    while (cin>>s>>p>>y>>j)
    {
        yertleAge = (j+d - p - y)/3;
        puffAge = (j+d - s - yertleAge)/2;
        spotAge = j+d - puffAge - yertleAge;
        cout<<spotAge<<" "<<puffAge<<" "<<yertleAge<<"\n";
    }
    return 0;
}