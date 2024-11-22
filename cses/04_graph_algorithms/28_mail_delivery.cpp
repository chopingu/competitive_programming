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

    vector<ll> vis(n), e_vis(m);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto [v, e_id]: al[u]) {
            if(!vis[v])
                dfs(v, dfs);

            e_vis[e_id] = 1;
        }
    };

    dfs(0, dfs);

    for(ll i = 0; i < m; i++) 
        if(!e_vis[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    vector<ll> ans, e(m);
    stack<ll> st({0});
    while(sz(st)) {
        ll u = st.top();
        while(--deg[u] >= 0 && e[al[u][deg[u]][1]]) {}

        if(deg[u] < 0) {
            ans.push_back(u);
            st.pop();
            continue;
        }

        e[al[u][deg[u]][1]] = 1;
        st.push(al[u][deg[u]][0]);
    }

    reverse(ans.begin(), ans.end());

    for(auto i: ans)
        cout << i + 1 << ' ';
}
