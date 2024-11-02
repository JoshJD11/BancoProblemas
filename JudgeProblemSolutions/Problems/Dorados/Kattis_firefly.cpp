#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//lo dejo para después

int main()
{
    int N,H,x;
    cin>>N>>H;
    vector<int>down;
    vector<int>up;
    for(int i=0;i<N;i++)
    {
      cin>>x;
      if(!(i%2)) down.push_back(x);
      else up.push_back(x);  
    }
    sort(down.begin(),down.end());
    sort(up.begin(),up.end());
    return 0;
}