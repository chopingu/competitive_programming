#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
    }

    ll ans = 0;
    vector<ll> mt(m, -1), vis1(n);
    for(ll i = 0; i < n; i++) {
        for(auto v: al[i])
            if(mt[v] == -1) {
                mt[v] = i;
                vis1[i] = 1;
                ans++;
                break;
            }
    }

    vector<ll> vis2(n);
    auto dfs = [&](ll u, auto&& dfs) -> ll {
        if(vis2[u]) 
            return 0;

        vis2[u] = 1;
        for(auto v: al[u]) 
            if(mt[v] == -1 || dfs(mt[v], dfs)) {
                mt[v] = u;
                return 1;
            }

        return 0;
    };

    for(ll i = 0; i < n; i++) {
        if(vis1[i]) continue;
        vis2.assign(n, 0);
        ans += dfs(i, dfs);
    }

    cout << ans << '\n';
    for(ll i = 0; i < m; i++) 
        if(mt[i] ^ -1) 
            cout << mt[i] + 1 << ' ' << i + 1 << '\n';
}
