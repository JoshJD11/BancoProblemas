#include<iostream> //ACCEPTED!!
using namespace std;
#include<vector>


int memo[2005][2005];


void clean(int cant, int capacity)
{
    for(int i=0;i<cant+2;i++)
        for(int j=0;j<capacity+2;j++) 
        {
            memo[i][j] = 0;
        }
}

void readMemo(vector<vector<int> >&v, int capacity, int cant)
{
    int hadToTake=0;
    vector<int>indexes;
    for(int i=0;i<cant;i++)
    {
        if(memo[i][capacity] != memo[i+1][capacity])
        {
            hadToTake++;
            indexes.push_back(i);
            capacity-= v[i][0];
        }
    }
    cout<<hadToTake<<'\n';
    for(int j=0;j<(int)indexes.size();j++)
    {
        if(j+1 == (int)indexes.size()) cout<<indexes[j]<<'\n';
        else cout<<indexes[j]<<" ";
    }

}


int knapsack(vector<vector<int> >&objects, int capacity, int index)
{
    if(capacity<0) return -(1<<(25));
    if(index == (int)objects.size()) return 0;
    if(memo[index][capacity]) return memo[index][capacity];
    return memo[index][capacity] = max(objects[index][1] + knapsack(objects,capacity - objects[index][0], index+1),knapsack(objects,capacity,index+1));
}



int main()
{
    int capacity,cantObjects,weight,value;
    while(cin>>capacity>>cantObjects)
    {
        vector<vector<int> >objects;
        while (cantObjects--)
        {
            cin>>value>>weight;
            objects.push_back({weight,value}); 
        }
        clean(objects.size(),capacity);
        knapsack(objects,capacity,0);
        readMemo(objects,capacity,objects.size());
    }
    return 0;
}