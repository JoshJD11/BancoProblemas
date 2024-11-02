#include<iostream> //time limit exceeded
using namespace std;
#include<algorithm>
#include<vector>
#define ulli long long int

int binarySearch(vector<ulli>array, ulli n, ulli target)
{
    ulli low = 0;
    ulli high = n - 1;

    while (low <= high)
    {
        ulli middle = (low + high) / 2;
        if (array[middle] == target)
            return 1;
        else if (array[middle] < target)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return 0;
}



void generateArray(vector<ulli>&v,ulli n,ulli m,ulli a,ulli c,ulli x)
{
    while(n--)
    {
        x = (a*x+c)%m;
        v.push_back(x);
    }
}



int main()
{
    ulli n,m,a,c,x,ans=0;
    cin>>n>>m>>a>>c>>x;
    vector<ulli>v;
    generateArray(v,n,m,a,c,x);
    ulli tam = v.size();
    for(ulli i=0;i<tam;i++){
        if(binarySearch(v,tam,v[i])) ans++;
    } 
    cout<<ans<<'\n';
    return 0;
}