#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<array<ll, 2>>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        al[a].push_back({b, c});
    }

    vector<ll> flag(n, -1); 
    auto dfs = [&](ll u, auto&& dfs) -> void {
        if(u == n - 1) {
            flag[u] = 1;
            return;
        }

        flag[u] = 0;
        for(auto [v, ign]: al[u]) {
            if(flag[v] == -1)
                dfs(v, dfs);

            flag[u] |= flag[v];
        }
    };

    dfs(0, dfs);

    vector<ll> dist(n, -1e18);
    dist[0] = 0;
    for(ll i = 0; i <= n; i++)
        for(ll u = 0; u < n; u++) 
            for(auto [v, w]: al[u]) 
                if(dist[u] > -1e18 && dist[u] + w > dist[v]) {
                    if(i == n - 1 && flag[v] == 1) {
                        cout << -1;
                        return 0;
                    }
                    dist[v] = dist[u] + w;
                }

    cout << dist[n - 1];
}
