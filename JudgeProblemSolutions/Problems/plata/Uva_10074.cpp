#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#include<stack>


int histogram(vector<int>&histogram)
{
    int ans = 0;
    stack<vector<int> > Stack;
    for(int i=0; i<(int)histogram.size(); i++)
    {
        int newHeight = histogram[i], newIndex = i;
        while(!Stack.empty() && newHeight<Stack.top()[0])
        {
            vector<int>top = Stack.top();
            Stack.pop();
            ans = max(ans,top[0]*(i-top[1]));
            newIndex = top[1];
        }
        Stack.push({newHeight, newIndex});
    }
    while(!Stack.empty())
    {
        int height = Stack.top()[0],position = Stack.top()[1];
        Stack.pop();
        ans = max(ans, height * ((int)histogram.size() - position));
    }
    return ans;
}


int main()
{
    int rows,columns,ans;
    char value;
    while(cin>>rows>>columns)
    {
        if(!rows && !columns) break;
        ans = 0;
        vector<vector<int> >land(rows+1, vector<int>(columns,0));
        for(int i=1;i<rows+1;i++)
        {
            for(int j=0;j<columns;j++)
            {
                cin>>value;
                if(value != '0') land[i][j] = 0;
                else land[i][j] = 1 + land[i-1][j];
            }
            ans = max(ans,histogram(land[i]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}