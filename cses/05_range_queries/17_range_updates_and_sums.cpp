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

    vector<ll> seg(4 * n), lzadd(4 * n), lzset(4 * n, -1);
    auto bld = [&](ll v, ll tl, ll tr, auto&& bld) -> void {
        if(tl == tr) {
            seg[v] = x[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        bld(2 * v, tl, tm, bld);
        bld(2 * v + 1, tm + 1, tr, bld);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    };

    bld(1, 0, n - 1, bld);

    auto push = [&](ll v, ll tl, ll tr) -> void {
        ll tm = tl + (tr - tl) / 2;
        if(lzset[v] ^ -1) {
            seg[2 * v] = lzset[v] * (tm - tl + 1);
            seg[2 * v + 1] = lzset[v] * (tr - tm);
            lzset[2 * v] = lzset[2 * v + 1] = lzset[v];
            lzadd[2 * v] = lzadd[2 * v + 1] = 0;
            lzset[v] = -1;
        }
        else if(lzadd[v]) {
            seg[2 * v] += lzadd[v] * (tm - tl + 1);
            seg[2 * v + 1] += lzadd[v] * (tr - tm);
            if(lzset[2 * v] ^ -1)
                lzset[2 * v] += lzadd[v];
            else
                lzadd[2 * v] += lzadd[v];

            if(lzset[2 * v + 1] ^ -1)
                lzset[2 * v + 1] += lzadd[v];
            else 
                lzadd[2 * v + 1] += lzadd[v];

            lzadd[v] = 0;
        }
    };

    auto setqry = [&](ll v, ll tl, ll tr, ll le, ll ri, ll val, auto&& setqry) -> void {
        if(le > ri)
            return;

        if(le == tl && ri == tr) {
            seg[v] = val * (tr - tl + 1);
            lzadd[v] = 0;
            lzset[v] = val;
            return;
        }
        push(v, tl, tr);
        ll tm = tl + (tr - tl) / 2;
        setqry(2 * v, tl, tm, le, min(tm, ri), val, setqry);
        setqry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, val, setqry);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    };

    auto addqry = [&](ll v, ll tl, ll tr, ll le, ll ri, ll val, auto&& addqry) -> void {
        if(le > ri)
            return;

        if(le == tl && ri == tr) {
            seg[v] += val * (tr - tl + 1);
            if(lzset[v] ^ -1) 
                lzset[v] += val;
            else 
                lzadd[v] += val;

            return;
        }
        push(v, tl, tr);
        ll tm = tl + (tr - tl) / 2;
        addqry(2 * v, tl, tm, le, min(tm, ri), val, addqry);
        addqry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, val, addqry);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    };

    auto qry = [&](ll v, ll tl, ll tr, ll le, ll ri, auto&& qry) -> ll {
        if(le > ri)
            return 0;

        if(le == tl && ri == tr) 
            return seg[v];

        push(v, tl, tr);
        ll tm = tl + (tr - tl) / 2;
        return qry(2 * v, tl, tm, le, min(tm, ri), qry) +
            qry(2 * v + 1, tm + 1, tr, max(tm + 1, le), ri, qry);
    };

    while(q--) {
        ll t;
        cin >> t;

        if(t == 1) {
            ll a, b, x;
            cin >> a >> b >> x, --a, --b;

            addqry(1, 0, n - 1, a, b, x, addqry);
            continue;
        }

        if(t == 2) {
            ll a, b, x;
            cin >> a >> b >> x, --a, --b;

            setqry(1, 0, n - 1, a, b, x, setqry);
            continue;
        }

        ll a, b;
        cin >> a >> b, --a, --b;

        cout << qry(1, 0, n - 1, a, b, qry) << '\n';
    }
}
