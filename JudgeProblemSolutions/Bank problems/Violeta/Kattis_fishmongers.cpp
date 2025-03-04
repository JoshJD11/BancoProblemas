#include <iostream> //accepted
#include <vector>
#include <algorithm>
using namespace std;


bool customComparator(const vector<int>& a, const vector<int>& b) {
    return a[1] > b[1]; 
}

long long fisherMan(const vector<vector<int>>& pescadores, const vector<int>& pescados) {
    long long res = 0;
    size_t indicePescados = 0;
    for (const auto& solicitud : pescadores) {
        if (indicePescados == pescados.size()) return res;

        long long sumPesos = 0;
        int cantidad = solicitud[0];

        for (size_t i = indicePescados; i < pescados.size(); ++i) {
            if (cantidad == 0) {
                indicePescados = i;
                break;
            }
            sumPesos += pescados[i];
            cantidad--;

            if (i == pescados.size() - 1) {
                indicePescados = pescados.size();
            }
        }
        res += sumPesos * solicitud[1];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> pescados(n);
    for (int i = 0; i < n; ++i) {
        cin>>pescados[i];
    }
    sort(pescados.rbegin(), pescados.rend());
    vector<vector<int>> pescadores(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin>>pescadores[i][0]>>pescadores[i][1];
    }
    sort(pescadores.begin(), pescadores.end(), customComparator);
    cout<<fisherMan(pescadores, pescados)<<'\n';
    return 0;
}
