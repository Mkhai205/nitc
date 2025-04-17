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


vector<pii> rook = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<char>> matrix;
int n, m;

bool is_valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
    for(pii a : rook) {
        int nx = x + a.first;
        int ny = y + a.second;
        if (is_valid(nx, ny) && matrix[nx][ny] == '.') {
            matrix[nx][ny] = '*'; // Mark as visited
            dfs(nx, ny);
        }
    }
}

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    matrix[x][y] = '*'; // Mark as visited
    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        for (pii a : rook) {
            int nx = curr.first + a.first;
            int ny = curr.second + a.second;
            if (is_valid(nx, ny) && matrix[nx][ny] == '.') {
                matrix[nx][ny] = '*'; // Mark as visited
                q.push({nx, ny});
            }
        }
    }
}


int main(){
    fastio;
    cin >> n >> m;
    matrix.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == '.') {
                cnt++;
                matrix[i][j] = '*'; // Mark as visited
                bfs(i, j);
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << matrix[i][j];
    //     }
    //     cout << endl;
    // }

    cout << cnt << endl;

    return 0;
}
