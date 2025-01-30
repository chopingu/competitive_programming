#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    ll timer = 0;
    vector<ll> in(n), out(n);
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        in[u] = timer++;
        for(auto v: al[u]) 
            if(v ^ p)
                dfs(v, u, dfs);

        out[u] = timer++;
    };

    dfs(0, 0, dfs);

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

    for(ll i = 0; i < n; i++)
        upd(in[i], x[i]);

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll a, b;
            cin >> a >> b, --a;

            upd(in[a], -x[a]);
            upd(in[a], x[a] = b);
            continue;
        }

        ll a;
        cin >> a, --a;
        cout << qry(out[a]) - qry(in[a] - 1) << '\n';
    }
}
