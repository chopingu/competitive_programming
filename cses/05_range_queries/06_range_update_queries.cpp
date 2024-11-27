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

    vector<ll> seg(4 * n, 0);
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[v] = x[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll le, ll ri, ll val, auto&& upd) -> void {
        if(le > ri) 
            return;

        if(le == tl && ri == tr) {
            seg[v] += val;
            return;
        }

        ll tm = tl + (tr - tl) / 2;
        upd(2 * v, tl, tm, le, min(tm, ri), val, upd);
        upd(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, val, upd);
    };

    auto qry = [&](ll v, ll tl, ll tr, ll pos, auto&& qry) -> ll {
        if(tl == tr)
            return seg[v];

        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            return seg[v] + qry(2 * v, tl, tm, pos, qry);

        return seg[v] + qry(2 * v + 1, tm + 1, tr, pos, qry);
    };

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll a, b, u;
            cin >> a >> b >> u, --a, --b;

            upd(1, 0, n - 1, a, b, u, upd);
            continue;
        }

        ll k;
        cin >> k, --k;

        cout << qry(1, 0, n - 1, k, qry) << '\n';
    }
}
