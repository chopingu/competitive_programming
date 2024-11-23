#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    if(n == 1) {
        cout << "01";
        return 0;
    }

    vector<ll> deg(1 << (n - 1));
    vector<vector<ll>> al(1 << (n - 1));
    for(ll i = 0; i < (1 << n); i++) {
        al[i >> 1].push_back(i & ((1 << (n - 1)) - 1));
        deg[i >> 1]++;
    }

    vector<ll> tour; 
    stack<ll> st({0});
    while(sz(st)) {
        ll u = st.top();
        if(--deg[u] < 0) {
            tour.push_back(u);
            st.pop();
            continue;
        }
        st.push(al[u][deg[u]]);
    }
    reverse(tour.begin(), tour.end());

    string ans;
    for(ll i = 0; i < n - 1; i++)
        ans.push_back('0');

    for(ll i = 1; i < sz(tour); i++)
        ans.push_back('0' + (tour[i] & 1));

    cout << ans;
}
