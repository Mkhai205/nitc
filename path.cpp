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

vector<vector<int>> matrix(20, vector<int>(20, 0));

void init() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool isSafe(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] == 0) return false;
    return true;
}

void solve(int x, int y, string path) {
    if(x == n-1 && y == m-1) {
        cout << path << endl;
        return;
    }

    if(isSafe(x+1, y)) {
        solve(x+1, y, path + "D");
    }
    if(isSafe(x, y+1)) {
        solve(x, y+1, path + "R");
    }
}

int main(){
    fastio;
    
    init();
    solve(0, 0, "");

    return 0;
}
