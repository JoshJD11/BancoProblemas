#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#include<algorithm>


int binarySearch(vector<int>&list, int num)
{
    int inf=0,sup=list.size()-1,mid=(inf+sup)/2;
    while(inf+1<sup)
    {
        if(list[mid] == num) return mid;
        if(list[mid]>num) sup = mid;
        else inf = mid;
        mid = (inf+sup)/2;
    }
    if(list[inf] == num) return inf;
    return (list[sup] == num)? sup:-1;
}


int main()
{
    int n,x,i,index;
    while(cin>>n && n!=0)
    {
        vector<int>Dummy;
        vector<int>listOne;
        vector<int>listTwo;
        for(i=0;i<n;i++){cin>>x;listOne.push_back(x); Dummy.push_back(x);}
        for(i=0;i<n;i++){cin>>x;listTwo.push_back(x);}
        sort(listOne.begin(),listOne.end());
        sort(listTwo.begin(),listTwo.end());
        for(i = 0; i<(int)Dummy.size();i++){index = binarySearch(listOne,Dummy[i]);cout<<listTwo[index]<<'\n';}
        cout<<'\n';
    }
    return 0;
}