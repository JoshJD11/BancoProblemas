#include <iostream>
using namespace std;

const int N = 7;
bool visited[N][N];
string path;
int ans = 0;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void search(int x, int y, int step) {
    if (x == N - 1 && y == 0) { 
        if (step == 48) ans++; 
        return;
    } if ((x == 6 || visited[x + 1][y]) && (x == 0 || visited[x - 1][y]) &&
        (y > 0 && !visited[x][y - 1]) && (y < 6 && !visited[x][y + 1])) return;
    if ((y == 6 || visited[x][y + 1]) && (y == 0 || visited[x][y - 1]) &&
        (x > 0 && !visited[x - 1][y]) && (x < 6 && !visited[x + 1][y])) return;
    visited[x][y] = true;
    if (path[step] != '?') {
        for (int i = 0; i < 4; i++) {
            if (dir[i] == path[step]) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                    search(nx, ny, step + 1);
                }
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                search(nx, ny, step + 1);
            }
        }
    }
    visited[x][y] = false;
}

int main() {
    cin >> path;
    search(0, 0, 0);
    cout << ans << endl;
    return 0;
}
