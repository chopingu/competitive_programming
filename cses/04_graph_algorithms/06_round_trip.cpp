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
            if(vis[v] ^ -1 && vis[u] ^ v) {
                ll cur = u;
                vector<ll> cy({u});
                while(cur ^ v) {
                    cur = vis[cur];
                    cy.push_back(cur);
                }
                cy.push_back(u);

                cout << sz(cy) << '\n';
                for(auto i: cy)
                    cout << i + 1 << ' ';

                exit(0);
            }
            else if(vis[v] == -1) {
                vis[v] = u;
                dfs(v, dfs);
            }
    };

    for(ll i = 0; i < n; i++) 
        if(vis[i] == -1) {
            vis[i] = i;
            dfs(i, dfs);
        }

    cout << "IMPOSSIBLE";
}
