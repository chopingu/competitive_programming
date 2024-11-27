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

    vector<ll> seg(4 * n);
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[v] = x[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll pos, ll val, auto && upd) -> void {
        if(tl == tr) {
            seg[v] = val;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            upd(2 * v, tl, tm, pos, val, upd);
        else
            upd(2 * v + 1, tm + 1, tr, pos, val, upd);

        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    };

    auto qry = [&](ll v, ll tl, ll tr, ll le, ll ri, auto&& qry) -> ll {
        if(le > ri) 
            return 1e18;

        if(le == tl && ri == tr) 
            return seg[v];

        ll tm = tl + (tr - tl) / 2;
        return min(qry(2 * v, tl, tm, le, min(tm, ri), qry), 
                qry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry));
    };

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll k, u;
            cin >> k >> u, --k;

            upd(1, 0, n - 1, k, u, upd);
            continue;
        }

        ll a, b;
        cin >> a >> b, --a, --b;

        cout << qry(1, 0, n - 1, a, b, qry) << '\n';
    }
}
