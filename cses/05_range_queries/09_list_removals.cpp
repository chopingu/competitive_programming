#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

/* CHEAT SOLUTION
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T>
using ost=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ost<array<ll, 2>> pbds;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        pbds.insert({i, a});
    }

    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a, --a;

        auto it = pbds.find_by_order(a);
        cout << (*it)[1] << ' ';

        pbds.erase(it);
    }
}
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    vector<ll> seg(4 * n);
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[v] = 1;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    };

    bld(1, 0, n - 1, bld);

    auto upd = [&](ll v, ll tl, ll tr, ll pos, auto&& upd) -> void {
        if(tl == tr) {
            seg[v] = 0;
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            upd(2 * v, tl, tm, pos, upd);
        else
            upd(2 * v + 1, tm + 1, tr, pos, upd);

        seg[v] = seg[2 * v] + seg[2 * v + 1];
    };

    auto qry = [&](ll v, ll tl, ll tr, ll le, ll ri, auto&& qry) -> ll {
        if(le > ri)
            return 0;

        if(le == tl && ri == tr)
            return seg[v];

        ll tm = tl + (tr - tl) / 2;
        return qry(2 * v, tl, tm, le, min(tm, ri), qry) + 
            qry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry);
    };

    for(ll i = 0; i < n; i++) {
        ll p;
        cin >> p;

        ll lo = 0, hi = n - 1, ans = 0;
        while(lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll flag = qry(1, 0, n - 1, 0, mid, qry);
            (flag >= p) ? ans = mid, hi = mid - 1 : lo = mid + 1;
        }

        cout << x[ans] << ' ';
        upd(1, 0, n - 1, ans, upd);
    }
}
