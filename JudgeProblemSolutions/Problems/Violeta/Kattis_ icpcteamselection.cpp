#include<iostream> //ACCEPTED
using namespace std;
#include<vector>
#include<algorithm>


int icpcSelection(vector<int>&students)
{
    int sum=0,pointer = students.size()-1;
    for(int i=0;i<(int)students.size();i+=2)
    {
        sum+=students[i+1];
        if(pointer - 1 == i+1) break;
        pointer--;
    }
    return sum;
}


int main(){
    int T,teams,student,cantStudents;
    cin>>T;
    while(T--){
        vector<int>students;
        cin>>teams;
        cantStudents=teams*3;
        while(cantStudents--)
        {
            cin>>student;
            students.push_back(student);
        }
        sort(students.begin(),students.end(),greater<int>());
        cout<<icpcSelection(students)<<'\n';
    }
    return 0;
}