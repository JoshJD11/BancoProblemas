#include<iostream>
using namespace std;
#include<vector>
#define ulli unsigned long long int


ulli absoluteValue(ulli a) {
    return (a<0)? -a:a;
}


ulli ulliMin(ulli a, ulli b) {
    return (a < b)? a:b;
}


ulli appleDivision(vector<ulli>&apples, ulli index, ulli leftWeight, ulli rightWeight) {
    if(index >= apples.size()) return absoluteValue(leftWeight - rightWeight);
    return ulliMin(appleDivision(apples, index + 1, leftWeight + apples[index], rightWeight), appleDivision(apples, index + 1, leftWeight, rightWeight + apples[index]));
}



int main() {

    ulli n;
    cin>>n;
    vector<ulli> apples;
    while(n--) {
        ulli weight;
        cin>>weight;
        apples.push_back(weight);
    }

    cout<<appleDivision(apples, 0, 0, 0)<<'\n';

    return 0;
}