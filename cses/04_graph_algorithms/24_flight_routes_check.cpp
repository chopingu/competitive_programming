#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n), al_t(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al_t[b].push_back(a);
    }

    vector<ll> vis(n), topo;
    auto dfs1 = [&](ll u, auto&& dfs1) -> void {
        vis[u] = 1;
        for(auto v: al[u])
            if(!vis[v])
                dfs1(v, dfs1);

        topo.push_back(u);
    };

    for(ll i = 0; i < n; i++)
        if(!vis[i])
            dfs1(i, dfs1);

    reverse(topo.begin(), topo.end());

    ll cnt = 0;
    vector<ll> scc(n, -1);
    auto dfs2 = [&](ll u, auto&& dfs2) -> void {
        scc[u] = cnt;
        for(auto v: al_t[u])
            if(scc[v] == -1)
                dfs2(v, dfs2);
    };

    for(ll i = 0; i < n; i++) 
        if(scc[topo[i]] == -1) {
            if(i) {
                cout << "NO\n" << topo[i] + 1 << ' ' << topo[i - 1] + 1;
                return 0;
            }
            dfs2(topo[i], dfs2);
            cnt++;
        }

    cout << "YES";
}
