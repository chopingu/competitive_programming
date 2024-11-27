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

    vector<ll> dist(n, -1);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        for(auto v: al[u])
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                dfs(v, dfs);
            }
    };

    dist[0] = 0;
    dfs(0, dfs);
    
    ll id = 0;
    for(ll i = 0; i < n; i++) 
        if(dist[i] > dist[id]) 
            id = i;

    dist.assign(n, -1);
    dist[id] = 0; 
    dfs(id, dfs);

    ll ans = 0;
    for(auto i: dist)
        ans = max(ans, i);

    cout << ans;
}
