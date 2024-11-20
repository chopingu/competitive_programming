#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> vis(n, -1);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        for(auto v: al[u]) 
            if(vis[v] ^ -1 && vis[v] == vis[u]) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
            else if(vis[v] == -1) {
                vis[v] = !vis[u];
                dfs(v, dfs);
            }
    };
    
    for(ll i = 0; i < n; i++) 
        if(vis[i] == -1) {
            vis[i] = 0;
            dfs(i, dfs);
        }

    for(ll i = 0; i < n; i++) 
        cout << vis[i] + 1 << ' ';
}
