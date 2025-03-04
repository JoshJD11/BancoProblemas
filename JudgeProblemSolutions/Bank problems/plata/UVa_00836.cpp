#include<iostream> //ACCEPTED!!
#include<vector>
#include<stack>
#include<string>
using namespace std;

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

int processMatrix(vector<vector<int>>&matrix){
    if((int)matrix.size() == 0) return 0;
    int ans = histogram(matrix[0]);
    for(int i=1;i<(int)matrix.size();i++){
        for(int j=0;j<(int)matrix[0].size();j++){
            if(matrix[i][j] == 1 && matrix[i-1][j] != 0) matrix[i][j] += matrix[i-1][j];
        }
        ans = max(ans,histogram(matrix[i]));
    }
    return ans;
}

int main()
{
    int t;  
    cin >> t;
    cin.ignore(); 
    cin.ignore(); 

    while (t--) {
        string line;
        vector<vector<int>> matrix;

        while (getline(cin, line) && !line.empty()) {
            vector<int> row;
            for (char c : line) {
                if (c == '0' || c == '1') { 
                    row.push_back(c - '0');
                }
            }
            matrix.push_back(row);
        }

        cout << processMatrix(matrix) << '\n';

        if (t > 0) {
            cout << endl;
        }
    }

    return 0;
}

//g++ -o UVa_00836 UVa_00836.cpp
// ./UVa_00836