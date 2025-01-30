#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> sub(n);
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        sub[u] = 1;
        for(auto v: al[u])
            if(v ^ p) {
                dfs(v, u, dfs);
                sub[u] += sub[v];
            }
    };

    dfs(0, -1, dfs);

    auto centroid = [&](ll u, ll p, auto&& centroid) -> ll {
        ll ans = u;
        for(auto v: al[u])
            if(v ^ p && sub[v] * 2 > n)
                ans = centroid(v, u, centroid);

        return ans;
    };

    cout << centroid(0, -1, centroid) + 1;
}
