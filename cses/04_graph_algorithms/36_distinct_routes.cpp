#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> cap(n, vector<ll>(n));
    vector<vector<array<ll, 2>>> al(n), al_u(n); 
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        cap[a][b]++;
        al[a].push_back({b, i});
        al_u[a].push_back({b, i});
        al_u[b].push_back({a, i});
    }

    vector<ll> p;
    auto bfs = [&](ll s, ll t) -> ll {
        p.assign(n, -1);
        p[s] = -2;
        queue<array<ll, 2>> q({{s, (ll)1e18}});
        while(sz(q)) {
            auto [u, flow] = q.front();
            q.pop();

            for(auto [v, ign]: al_u[u])
                if(p[v] == -1 && cap[u][v]) {
                    p[v] = u;
                    ll nw_flow = min(flow, cap[u][v]);
                    if(v == t)
                        return nw_flow;

                    q.push({v, nw_flow});
                }
        }

        return 0;
    };

    ll mx_flow = 0, aug;
    while(aug = bfs(0, n - 1)) {
        mx_flow += aug;
        ll cur = n - 1;
        while(cur) {
            ll prev = p[cur];
            cap[prev][cur] -= aug;
            cap[cur][prev] += aug;
            cur = prev;
        }
    }

    vector<vector<ll>> ans;
    vector<ll> vis(n), e_vis(m);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        ans.back().push_back(u);
        vis[u] = 1;
        if(u == n - 1)
            return;

        for(auto [v, id]: al[u])
            if(!vis[v] && !cap[u][v] && !e_vis[id]) {
                e_vis[id] = 1;
                dfs(v, dfs);
                break;
            }
    };

    cout << mx_flow << '\n';
    for(ll i = 0; i < mx_flow; i++) {
        ans.emplace_back();
        vis.assign(n, 0);
        dfs(0, dfs);
        cout << sz(ans.back()) << '\n';
        for(ll j = 0; j < sz(ans.back()); j++) 
            cout << ans.back()[j] + 1 << (" \n")[j == sz(ans.back()) - 1];
    }
}
