#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> h(n);
    for(auto &i: h)
        cin >> i;

    vector<ll> seg(4 * n);
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[v] = h[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll pos, ll val, auto&& upd) -> void {
        if(tl == tr) {
            seg[v] += val;
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
            return -1e18;

        if(le == tl && ri == tr)
            return seg[v];

        ll tm = tl + (tr - tl) / 2;
        return max(qry(2 * v, tl, tm, le, min(tm, ri), qry), 
                qry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry));
    };

    for(ll i = 0; i < m; i++) {
        ll r;
        cin >> r;

        ll lo = 0, hi = n - 1, ans = -1;
        while(lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll flag = qry(1, 0, n - 1, 0, mid, qry);
            (flag >= r) ? ans = mid, hi = mid - 1 : lo = mid + 1;
        }

        if(ans ^ -1)
            upd(1, 0, n - 1, ans, -r, upd);

        cout << ans + 1 << ' ';
    }
}
