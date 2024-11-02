#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#include<queue>


void notConnected(vector<bool>&visited)
{
    for(int i=1;i<(int)visited.size();i++)
    {
        if(!visited[i]) cout<<i<<'\n';
    }
}


bool isConnected(int n, vector<vector<int>>&adyList, vector<bool>&visited)
{
    int curr,ady,cont=1;
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty())
    {
        if(cont == n) break;
        curr = q.front();
        q.pop();
        for(int i=0;i<(int)adyList[curr].size();i++)
        {
            ady = adyList[curr][i];
            if(!visited[ady])
            {
                q.push(ady);
                cont++;
                visited[ady] = true;
            }
        }
    }
    return cont == n;
}


int main(){
    int N,M,x,y;
    cin>>N>>M;
    vector<vector<int>>adyList;
    vector<bool>visited;
    visited.resize(N+1);
    adyList.resize(N+1);
    while (M--)
    {
        cin>>x>>y;
        adyList[x].push_back(y);
        adyList[y].push_back(x);
    }
    if(isConnected(N,adyList,visited)) cout<<"Connected\n";
    else notConnected(visited);
    return 0;
}
