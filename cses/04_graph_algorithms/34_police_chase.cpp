#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n);
    vector<vector<ll>> cap(n, vector<ll>(n));
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        cap[a][b]++, cap[b][a]++;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> p(n);
    auto bfs = [&](ll s, ll t) -> ll {
        p.assign(n, -1);
        p[s] = -2;
        queue<array<ll, 2>> q({{s, (ll)1e18}});
        while(sz(q)) {
            auto [u, aug_flow] = q.front();
            q.pop();

            for(auto v: al[u])
                if(p[v] == -1 && cap[u][v]) {
                    p[v] = u;
                    ll nw_flow = min(aug_flow, cap[u][v]);
                    if(v == t)
                        return nw_flow;

                    q.push({v, nw_flow});
                }
        }

        return 0;
    };

    vector<vector<ll>> flow(n, vector<ll>(n));
    ll mx_flow = 0, aug_flow;
    while(aug_flow = bfs(0, n - 1)) {
        mx_flow += aug_flow;
        ll cur = n - 1;
        while(cur) {
            ll prev = p[cur];
            cap[prev][cur] -= aug_flow;
            cap[cur][prev] += aug_flow;
            cur = prev;
        }
    }

    vector<ll> vis(n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto v: al[u])
            if(!vis[v] && cap[u][v])
                dfs(v, dfs);
    };

    dfs(0, dfs);

    cout << mx_flow << '\n';
    for(ll u = 0; u < n; u++) {
        if(!vis[u]) continue;
        for(auto v: al[u]) 
            if(!vis[v])
                cout << u + 1 << ' ' << v + 1 << '\n';
    }
}
