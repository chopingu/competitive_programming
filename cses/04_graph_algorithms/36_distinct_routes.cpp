#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<array<ll, 2>>> al(n);
    vector<vector<ll>> al_u(n), cap(n, vector<ll>(n));
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back({b, i});
        al_u[a].push_back(b);
        al_u[b].push_back(a);
        cap[a][b] = 1;
    }

    vector<ll> p(n);
    auto bfs = [&](ll s, ll t) -> ll {
        p.assign(n, -1);
        p[s] = -2;
        queue<array<ll, 2>> q({{s, (ll)1e18}});
        while(sz(q)) {
            auto [u, aug] = q.front();
            q.pop();

            for(auto v: al_u[u])
                if(p[v] == -1 && cap[u][v]) {
                    p[v] = u;
                    ll nw_aug = min(aug, cap[u][v]);
                    if(v == t)
                        return nw_aug;

                    q.push({v, nw_aug});
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

    vector<ll> vis(m), pt;
    auto dfs = [&](ll u, auto&& dfs) -> void {
        pt.push_back(u);
        if(u == n - 1)
            return;

        for(auto [v, id]: al[u])
            if(!vis[id] && !cap[u][v]) {
                dfs(v, dfs);
                vis[id] = 1;
                return;
            }
    };

    cout << mx_flow << '\n';
    for(ll i = 0; i < mx_flow; i++) {
        pt.clear();
        dfs(0, dfs);

        cout << sz(pt) << '\n';
        for(ll j = 0; j < sz(pt); j++) 
            cout << pt[j] + 1 << (" \n")[j == sz(pt) - 1];
    }
}
