#include<iostream>  //ACCEPTED
using namespace std;


class node{
    public:
        node* father;
        int value;
        int money;
        node(int value, int money){
            this->father = this;
            this->value = value;
            this->money = money;
        }
};


node* Find(node*A)
{
    return (A->father->value == A->value)? A : Find(A->father);
}


void Union(node*A, node*B)
{
    node* FA = Find(A);
    node* FB = Find(B);
    
    if(FA->value != FB->value){
        FA -> father = FB;
        FB -> money += FA ->money;
    }
}


int main(){
    int n,m,doubt,x,y;
    bool flag = false;
    cin>>n>>m;
    node* arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>doubt;
        arr[i] = new node(i,doubt);
    }
    while(m--)
    {
        cin>>x>>y;
        Union(arr[x],arr[y]);
    }
    for(int j=0;j<n;j++)
    {
         if(Find(arr[j])->money != 0)
         {
            flag = true;
            break;
         } 
    }
    if(flag) cout<<"IMPOSSIBLE\n";
    else cout<<"POSSIBLE\n";
    return 0;
}