#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    vector<array<ll, 4>> seg(4 * n);
    auto merge = [&](ll v) -> void {
        seg[v][0] = max({seg[2 * v][0], seg[2 * v + 1][0], seg[2 * v][2] + seg[2 * v + 1][1]});
        seg[v][1] = max(seg[2 * v][1], seg[2 * v][3] + seg[2 * v + 1][1]);
        seg[v][2] = max(seg[2 * v + 1][2], seg[2 * v + 1][3] + seg[2 * v][2]);
        seg[v][3] = seg[2 * v][3] + seg[2 * v + 1][3];
    };

    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            for(ll i = 0; i < 3; i++)
                seg[v][i] = max(0ll, x[tl]);

            seg[v][3] = x[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        merge(v);
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll pos, ll val, auto&& upd) -> void {
        if(tl == tr) {
            for(ll i = 0; i < 3; i++)
                seg[v][i] = max(0ll, val);

            seg[v][3] = val;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm) 
            upd(2 * v, tl, tm, pos, val, upd);
        else
            upd(2 * v + 1, tm + 1, tr, pos, val, upd);

        merge(v);
    };

    for(ll i = 0; i < m; i++) {
        ll k, x;
        cin >> k >> x, --k;

        upd(1, 0, n - 1, k, x, upd);

        cout << seg[1][0] << '\n';
    }
}
