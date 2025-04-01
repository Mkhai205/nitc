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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    fastio;
    int n; cin >> n;

    vector<pair<int, int>> activity(n);

    for(pair<int, int> &x : activity) {
        cin >> x.first;
    }

    for(auto &x : activity) {
        cin >> x.second;
    }



    sort(activity.begin(), activity.end(), cmp);

    cout << endl;

    for(auto &x : activity) {
        cout << x.first << " ";
    }
    cout << endl;

    for(auto &x : activity) {
        cout << x.second << " ";
    }

    cout << endl;

    int ans = 0;

    int last_end_time = -1;
    
    for(pair<int, int> &x : activity) {
        if(x.first >= last_end_time) {
            ans++;
            last_end_time = x.second;
        }
    }

    cout << ans << endl;

    return 0;
}

