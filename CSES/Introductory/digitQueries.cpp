#include<iostream>
using namespace std;
#define ulli unsigned long long int

int main() {
    int q;
    cin >> q;
    while (q--) {
        ulli k;
        cin >> k;
        ulli len = 1, count = 9, start = 1;
        while (k > len * count) {
            k -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }
        ulli num = start + (k - 1) / len;
        string s = to_string(num);
        cout << s[(k - 1) % len] << '\n';
    }
    return 0;
}
