#pragma GCC optimize ("Ofast,inline") 
#pragma GCC optimize ("unroll-loops")

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

    vector<ll> sub(n), heavy(n, -1), dist(n), pr(n);
    auto dfs1 = [&](ll u, ll p, auto&& dfs1) -> void {
        sub[u] = 1;
        ll mx_c = 0;
        for(auto v: al[u])
            if(v ^ p) {
                pr[v] = u;
                dist[v] = dist[u] + 1;
                dfs1(v, u, dfs1);
                sub[u] += sub[v];
                if(sub[v] > mx_c) 
                    mx_c = sub[v], heavy[u] = v;
            }
    };

    dfs1(0, -1, dfs1);

    ll timer = 0;
    vector<ll> head(n), id(n);
    auto dfs2 = [&](ll u, ll p, ll h, auto&& dfs2) -> void {
        id[u] = timer++;
        head[u] = h;
        if(heavy[u] ^ -1) {
            dfs2(heavy[u], u, h, dfs2);
        }

        for(auto v: al[u])
            if(v ^ p && v ^ heavy[u]) 
                dfs2(v, u, v, dfs2);
    };

    dfs2(0, -1, 0, dfs2);

    vector<ll> seg(4 * timer);
    auto upd = [&](ll v, ll tl, ll tr, ll pos, ll val, auto&& upd) -> void {
        if(tl == tr) {
            seg[v] = val;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            upd(2 * v, tl, tm, pos, val, upd);
        else 
            upd(2 * v + 1, tm + 1, tr, pos, val, upd);

        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    };

    auto qry = [&](ll v, ll tl, ll tr, ll le, ll ri, auto&& qry) -> ll {
        if(le > ri)
            return 0;

        if(le == tl && ri == tr) 
            return seg[v];

        ll tm = tl + (tr - tl) / 2;
        return max(qry(2 * v, tl, tm, le, min(tm, ri), qry),
                qry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry));
    };

    for(ll i = 0; i < n; i++)
        upd(1, 0, timer - 1, id[i], x[i], upd);

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll a, b;
            cin >> a >> b, --a;

            upd(1, 0, timer - 1, id[a], x[a] = b, upd);
            continue;
        }

        ll a, b;
        cin >> a >> b, --a, --b;

        ll ans = 0;
        while(head[a] ^ head[b]) {
            if(dist[head[a]] < dist[head[b]])
                swap(a, b);

            ans = max(ans, qry(1, 0, timer - 1, id[head[a]], id[a], qry));
            a = pr[head[a]];
        }
        if(dist[a] > dist[b])
            swap(a, b);

        ans = max(ans, qry(1, 0, timer - 1, id[a], id[b], qry));
        cout << ans << ' ';
    }
}
