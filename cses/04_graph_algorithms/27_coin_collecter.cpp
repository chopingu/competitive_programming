#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> k(n);
    for(auto &i: k)
        cin >> i;

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

    vector<ll> scc(n, -1);
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

    vector<ll> vals(cnt);
    for(ll i = 0; i < n; i++)
        vals[scc[i]] += k[i];

    set<array<ll, 2>> st;
    vector<vector<ll>> al_scc(cnt);
    for(ll i = 0; i < n; i++)
        for(auto j: al[i])
            if(st.find({scc[i], scc[j]}) == st.end()) {
                st.insert({scc[i], scc[j]});
                al_scc[scc[i]].push_back(scc[j]);
            }

    vector<ll> memo(cnt, -1);
    auto dp = [&](ll u, auto&& dp) -> ll {
        ll &ans = memo[u];
        if(ans ^ -1)
            return ans;

        ans = 0;
        for(auto v: al_scc[u])
            ans = max(ans, dp(v, dp));

        ans += vals[u];

        return ans;
    };

    ll ans = 0;
    for(ll i = 0; i < cnt; i++)
        ans = max(ans, dp(i, dp));

    cout << ans;
}
