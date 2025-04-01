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

int n;

vector<int> cols(10, 0);

bool isSafe(int row, int col) {
    for(int i=1; i<row; i++) {
        if(cols[i] == col || abs(cols[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solve(int row) {
    if(row > n) {
        for(int i=1; i<=n; i++) {
            cout << i << " " << cols[i] << endl;
        }
        return true;
    }

    for(int i=n; i>=1; i--) {
        if(isSafe(row, i)) {
            cols[row] = i;
            if(solve(row + 1)) {
                return true;
            }
        }
    }
    return false;
}

int cnt = 0;

int step = 0;

void solve2(int row) {
    if(row > n) {
        cnt++;
        return;
    }

    for(int i=1; i<=n; i++) {
        step++;
        if(isSafe(row, i)) {
            solve2(row + 1);
        }
    }
    return;
}


int main(){
    fastio;
    cin >> n;

    solve2(1);

    cout << cnt << " " << step << endl;

    return 0;
}
