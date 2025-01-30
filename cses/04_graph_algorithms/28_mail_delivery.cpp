#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> deg(n);
    vector<vector<array<ll, 2>>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        deg[a]++, deg[b]++;
        al[a].push_back({b, i});
        al[b].push_back({a, i});
    }

    for(ll i = 0; i < n; i++) 
        if(deg[i] & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    vector<ll> e_vis(m), vis(n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto [v, id]: al[u]) {
            e_vis[id] = 1;
            if(!vis[v])
                dfs(v, dfs);
        }
    };

    dfs(0, dfs);

    for(ll i = 0; i < m; i++)
        if(!e_vis[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    e_vis.assign(m, 0);

    vector<ll> ans;
    stack<ll> s({0});
    while(sz(s)) {
        ll u = s.top();
        while(--deg[u] >= 0 && e_vis[al[u][deg[u]][1]]) {}
        if(deg[u] < 0) {
            s.pop();
            ans.push_back(u);
            continue;
        }
        e_vis[al[u][deg[u]][1]] = 1;
        s.push(al[u][deg[u]][0]);
    }
    reverse(ans.begin(), ans.end());

    for(auto i: ans)
        cout << i + 1 << ' ';
}
