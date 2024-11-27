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

    vector<vector<ll>> seg(2, vector<ll>(4 * n));
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[0][v] = x[tl] - tl;
            seg[1][v] = x[tl] + tl;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        seg[0][v] = min(seg[0][2 * v], seg[0][2 * v + 1]);
        seg[1][v] = min(seg[1][2 * v], seg[1][2 * v + 1]);
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll pos, ll val, auto&& upd) -> void {
        if(tl == tr) {
            seg[0][v] = val - tl;
            seg[1][v] = val + tl;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm) 
            upd(2 * v, tl, tm, pos, val, upd);
        else 
            upd(2 * v + 1, tm + 1, tr, pos, val, upd);

        seg[0][v] = min(seg[0][2 * v], seg[0][2 * v + 1]);
        seg[1][v] = min(seg[1][2 * v], seg[1][2 * v + 1]);
    };

    auto qry = [&](ll id, ll v, ll tl, ll tr, ll le, ll ri, auto&& qry) -> ll {
        if(le > ri)
            return 1e15;

        if(le == tl && ri == tr) 
            return seg[id][v];

        ll tm = tl + (tr - tl) / 2;
        return min(qry(id, 2 * v, tl, tm, le, min(tm, ri), qry),
                qry(id, 2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry));
    };

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll k, x;
            cin >> k >> x, --k;

            upd(1, 0, n - 1, k, x, upd);
            continue;
        }

        ll k;
        cin >> k, --k;

        cout << min(qry(0, 1, 0, n - 1, 0, k, qry) + k, qry(1, 1, 0, n - 1, k, n - 1, qry) - k) << '\n';
    }
}
