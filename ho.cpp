#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define MOD 1000000007
#define INF 1e18

vector<pii> queen = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<pii> knight = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
vector<pii> bishop = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<pii> rook = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

template<class X, class Y>
    bool minimize(X &x, const Y &y){
        if(x > y){
            x = y;
            return true;
        } return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y){
        if(x < y){
            x = y;
            return true;
        } return false;
    }

/* END OF TEMPLATE */

int n, m;

vector<vector<int>> matrix;

int ans = -1;

bool is_valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int x, int y) {
    int cnt = 0;
    queue<pii> q;
    q.push({x, y});
    cnt += matrix[x][y];
    matrix[x][y] = 0; // Mark as visited
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (pii a : rook) {
            int nx = curr.first + a.first;
            int ny = curr.second + a.second;
            if (is_valid(nx, ny) && matrix[nx][ny] != 0) {
                cnt += matrix[nx][ny];
                matrix[nx][ny] = 0; // Mark as visited
                q.push({nx, ny});
            }
        }
    }
    cout << "cnt: " << cnt << endl;
    ans = max(ans, cnt);
}

int main(){
    fastio;
    cin >> n >> m;
    matrix.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0){
                bfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
