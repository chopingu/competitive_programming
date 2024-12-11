#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    ll time = 0;
    vector<ll> tin(n), tout(n), dist(n);
    vector<vector<ll>> jmp(n, vector<ll>(31));
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        tin[u] = time++;
        jmp[u][0] = p;
        for(ll i = 1; i <= 30; i++)
            jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];

        for(auto v: al[u])
            if(v ^ p) {
                dist[v] = dist[u] + 1;
                dfs(v, u, dfs);
            }

        tout[u] = time++;
    };

    dfs(0, 0, dfs);

    auto anc = [&](ll a, ll b) -> bool {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };

    auto lca = [&](ll a, ll b) -> ll {
        if(anc(a, b))
            return a;

        if(anc(b, a))
            return b;

        for(ll i = 30; i >= 0; i--)
            if(!anc(jmp[a][i], b))
                a = jmp[a][i];

        return jmp[a][0];
    };

    while(q--) {
        ll a, b;
        cin >> a >> b, --a, --b;

        cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
    }
}
