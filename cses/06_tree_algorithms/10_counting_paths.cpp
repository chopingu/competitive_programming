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

    ll timer = 0;
    vector<ll> in(n), out(n);
    vector<vector<ll>> jmp(n, vector<ll>(31));
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        in[u] = timer++;
        jmp[u][0] = p;
        for(ll i = 1; i <= 30; i++) 
            jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];

        for(auto v: al[u]) 
            if(v ^ p)
                dfs(v, u, dfs);

        out[u] = timer++;
    };

    dfs(0, 0, dfs);

    auto anc = [&](ll a, ll b) -> bool {
        return in[a] <= in[b] && out[a] >= out[b];
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

    vector<ll> ft(timer + 1);
    auto upd = [&](ll id, ll val) -> void {
        for(++id; id <= timer; id += id & -id)
            ft[id] += val;
    };

    auto qry = [&](ll id) -> ll {
        ll sum = 0;
        for(++id; id; id -= id & -id)
            sum += ft[id];

        return sum;
    };

    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        ll c = lca(a, b);
        upd(in[c], -1);
        if(c)
            upd(in[jmp[c][0]], -1);

        upd(in[a], 1);
        upd(in[b], 1);
    }

    for(ll i = 0; i < n; i++) 
        cout << qry(out[i]) - qry(in[i] - 1) << ' ';
}
