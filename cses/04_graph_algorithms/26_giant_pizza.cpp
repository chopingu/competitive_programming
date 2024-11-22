#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(2 * m), al_t(2 * m);
    for(ll i = 0; i < n; i++) {
        vector<string> s(4);
        for(auto &j: s)
            cin >> j;

        ll u = stoll(s[1]) - 1 + m * (s[0] == "-");
        ll v = stoll(s[3]) - 1 + m * (s[2] == "-");

        al[(u + m) % (2 * m)].push_back(v);
        al[(v + m) % (2 * m)].push_back(u);
        al_t[v].push_back((u + m) % (2 * m));
        al_t[u].push_back((v + m) % (2 * m));
    }

    vector<ll> vis(2 * m), topo;
    auto dfs1 = [&](ll u, auto&& dfs1) -> void {
        vis[u] = 1;
        for(auto v: al[u])
            if(!vis[v])
                dfs1(v, dfs1);

        topo.push_back(u);
    };

    for(ll i = 0; i < 2 * m; i++) 
        if(!vis[i])
            dfs1(i, dfs1);

    reverse(topo.begin(), topo.end());

    vector<ll> scc(2 * m, -1);
    auto dfs2 = [&](ll u, ll id, auto&& dfs2) -> void {
        scc[u] = id;
        for(auto v: al_t[u]) 
            if(scc[v] == -1)
                dfs2(v, id, dfs2);
    };

    ll cnt = 0;
    for(auto i: topo)
        if(scc[i] == -1)
            dfs2(i, cnt++, dfs2);

    for(ll i = 0; i < m; i++)
        if(scc[i] == scc[i + m]) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    for(ll i = 0; i < m; i++)
        if(scc[i] < scc[i + m])
            cout << "- ";
        else 
            cout << "+ ";
}
