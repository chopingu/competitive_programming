//#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O3,inline")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    const uint64_t C=ll(2e18*acos(0))+71;
    const int RANDOM=chrono::high_resolution_clock::now().time_since_epoch().count();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

/* SPARSE SEGTREE TOO SLOW
struct Node {
    ll tl, tr, cnt;
    Node *cle, *cri;

    Node(ll tl, ll tr) : tl(tl), tr(tr), cnt(0), cle(0), cri(0) {}

    void push() {
        ll tm = tl + (tr - tl) / 2;
        if(!cle)
            cle = new Node(tl, tm);
        if(!cri)
            cri = new Node(tm + 1, tr);
    }

    void upd(ll pos, ll val) {
        if(tl == tr) {
            cnt += val;
            return;
        }
        push();
        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            cle->upd(pos, val);
        else
            cri->upd(pos, val);

        cnt = cle->cnt + cri->cnt;
    }

    ll qry(ll le, ll ri) {
        if(le > ri)
            return 0;

        if(le == tl && ri == tr) 
            return cnt;

        ll tm = tl + (tr - tl) / 2;
        ll ans = 0;
        if(cle)
            ans += cle->qry(le, min(tm, ri));
        if(cri)
            ans += cri->qry(max(tm + 1, le), ri);

        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    Node seg(0, (ll)1e9);
    vector<ll> p(n);
    for(auto &i: p)
        cin >> i, seg.upd(i, 1);

    while(q--) {
        char t;
        cin >> t;

        if(t == '!') {
            ll k, x;
            cin >> k >> x, --k;

            seg.upd(p[k], -1);
            seg.upd(x, 1);
            p[k] = x;

            continue;
        }

        ll a, b;
        cin >> a >> b;

        cout << seg.qry(a, b) << '\n';
    }
}
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> vals;
    vector<ll> p(n);
    for(auto &i: p)
        cin >> i, vals.push_back(i);

    vector<array<ll, 3>> qrs;
    for(ll i = 0; i < q; i++) {
        char t;
        cin >> t;

        if(t == '!') {
            ll k, x;
            cin >> k >> x, --k;

            qrs.push_back({0, k, x});
            vals.push_back(x);
            continue;
        }

        ll a, b;
        cin >> a >> b;

        qrs.push_back({1, a, b});
        vals.push_back(a);
        vals.push_back(b);
    }

    sort(vals.begin(), vals.end());

    ll cnt = 0;
    gp_hash_table<ll, ll, chash> comp;
    for(auto i: vals)
        if(comp.find(i) == comp.end())
            comp[i] = cnt++;

    vector<ll> seg(4 * sz(comp));
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

    for(auto i: p)
        upd(1, 0, sz(comp) - 1, comp[i], 1, upd);

    for(auto [a, b, c]: qrs) {
        if(!a) {
            upd(1, 0, sz(comp) - 1, comp[p[b]], -1, upd);
            upd(1, 0, sz(comp) - 1, comp[c], 1, upd);
            p[b] = c;
            continue;
        }

        cout << qry(1, 0, sz(comp) - 1, comp[b], comp[c], qry) << '\n';
    }
}

/* WITH FENWICK TREE
int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> vals;
    vector<ll> p(n);
    for(auto &i: p)
        cin >> i, vals.push_back(i);

    vector<array<ll, 3>> qrs;
    for(ll i = 0; i < q; i++) {
        char t;
        cin >> t;

        if(t == '!') {
            ll k, x;
            cin >> k >> x, --k;

            qrs.push_back({0, k, x});
            vals.push_back(x);
            continue;
        }

        ll a, b;
        cin >> a >> b;

        qrs.push_back({1, a, b});
        vals.push_back(a);
        vals.push_back(b);
    }

    sort(vals.begin(), vals.end());

    ll cnt = 0;
    gp_hash_table<ll, ll, chash> comp;
    for(auto i: vals)
        if(comp.find(i) == comp.end())
            comp[i] = cnt++;

    vector<ll> ft(cnt + 1);
    auto upd = [&](ll id, ll val) -> void {
        for(++id; id <= cnt; id += id & -id)
            ft[id] += val;
    };

    auto qry = [&](ll id) -> ll {
        ll ans = 0;
        for(++id; id; id -= id & -id)
            ans += ft[id];

        return ans;
    };

    for(auto i: p)
        upd(comp[i], 1);

    for(auto [a, b, c]: qrs) {
        if(!a) {
            upd(comp[p[b]], -1);
            upd(comp[c], 1);
            p[b] = c;
            continue;
        }
        cout << qry(comp[c]) - qry(comp[b] - 1) << '\n';
    }
}
*/
