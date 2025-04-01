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

void egyptian_representation(int a, int b) {
    if(a == 0 || b == 0) return;
    
    if(b % a == 0) {
        cout << 1 << "/" << b / a << endl;
        return;
    }

    int x = b /a + 1;
    cout << 1 << " / " << x << endl;
    return egyptian_representation(a * x - b, b * x);
}


int main(){
    fastio;
    int a, b; cin >> a >> b;

    egyptian_representation(a, b);

    return 0;
}
