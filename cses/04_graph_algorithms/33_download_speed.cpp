#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> cap(n, vector<ll>(n)), al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        cap[a][b] += c;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> p;
    auto bfs = [&](ll s, ll t) -> ll {
        p.assign(n, -1);
        p[s] = -2;
        queue<array<ll, 2>> q({{s, (ll)1e18}});
        while(sz(q)) {
            auto [u, flow] = q.front();
            q.pop();

            for(auto v: al[u]) 
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

    cout << mx_flow;
}
