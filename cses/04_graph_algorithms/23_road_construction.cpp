#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

struct DSU {
    vector<ll> r, p, s;
    multiset<ll> szs;

    DSU(ll n) {
        r.assign(n, 0);
        p.assign(n, 0);
        s.assign(n, 0);
        szs.clear();
        for(ll i = 0; i < n; i++) {
            p[i] = i; 
            s[i] = 1;
            szs.insert(1);
        }
    }

    ll findset(ll u) { return (p[u] == u) ? u : p[u] = findset(p[u]); }

    void unionset(ll u, ll v) {
        ll x = findset(u), y = findset(v);
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) r[y]++;
        szs.erase(szs.find(s[y]));
        s[y] += s[x];
        szs.erase(szs.find(s[x]));
        szs.insert(s[y]);
        p[x] = y;
    }

    array<ll, 2> qry() {
        return {sz(szs), *szs.rbegin()};
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    DSU dsu(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        dsu.unionset(a, b);
        auto [cnt, s] = dsu.qry();
        cout << cnt << ' ' << s << '\n';
    }
}
