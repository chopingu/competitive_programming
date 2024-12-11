#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    ll time = 0;
    vector<ll> tin(n), tout(n);
    vector<vector<ll>> jmp(n, vector<ll>(31));
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        tin[u] = time++;
        jmp[u][0] = p;
        for(ll i = 1; i <= 30; i++) 
            jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];

        for(auto v: al[u])
            if(v ^ p)
                dfs(v, u, dfs);

        tout[u] = time++;
    };

    dfs(0, 0, dfs);

    auto anc = [&](ll a, ll b) -> bool {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };

    auto lca = [&](ll a, ll b) -> ll {
        if(anc(a, b)) return a;
        if(anc(b, a)) return b;

        for(ll i = 30; i >= 0; i--) 
            if(!anc(jmp[a][i], b))
                a = jmp[a][i];

        return jmp[a][0];
    };

    vector<ll> ft(time + 1);
    auto upd = [&](ll id, ll val) -> void {
        for(++id; id <= time; id += id & -id) 
            ft[id] += val;
    };

    auto qry = [&](ll id) -> ll {
        ll ans = 0;
        for(++id; id; id -= id & -id) 
            ans += ft[id]; 

        return ans;
    };

    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        upd(tin[lca(a, b)], 1);
        upd(tin[a] + 1, -1);
        upd(tout[a], 1);
        upd(tin[b] + 1, -1);
        upd(tout[b], 1);
    }

    for(ll i = 0; i < n; i++) 
        cout << qry(tin[i]) << ' ';
}
