#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

struct DSU {
    ll cnt;
    vector<ll> r, p;

    DSU(ll n) : cnt(n) {
        r.assign(n, 0);
        p.assign(n, 0);
        for(ll i = 0; i < n; i++)
            p[i] = i;
    }

    ll findset(ll u) { return (p[u] == u) ? u : p[u] = findset(p[u]); }

    void unionset(ll u, ll v) {
        ll x = findset(u), y = findset(v);
        if(x == y) return;
        if(r[x] > r[y]) swap(x,  y);
        if(r[x] == r[y]) r[y]++;
        p[x] = y, --cnt;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> e;
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        e.push_back({c, a, b});
    }
    sort(e.begin(), e.end());

    ll ans = 0;
    DSU dsu(n);
    for(auto [c, a, b]: e) {
        if(dsu.findset(a) == dsu.findset(b))
            continue;

        ans += c;
        dsu.unionset(a, b);
    }

    if(dsu.cnt ^ 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << ans;
}
