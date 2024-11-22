#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<array<ll, 2>>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        al[a].push_back({b, c});
    }

    vector<ll> dist(n, 1e15), pr(n, -1);
    ll x;
    for(ll i = 0; i < n; i++) {
        x = -1;
        for(ll u = 0; u < n; u++)
            for(auto [v, w]: al[u])
                if(dist[u] + w < dist[v]) {
                    dist[v] = max((ll)-1e15, dist[u] + w);
                    pr[v] = u, x = v;
                }

        if(x == -1)
            break;
    }

    if(x == -1) {
        cout << "NO";
        return 0;
    }

    for(ll i = 0; i < n; i++)
        x = pr[x];

    vector<ll> cy;
    for(ll cur = x;; cur = pr[cur]) {
        cy.push_back(cur);
        if(cur == x && sz(cy) > 1)
            break;
    }
    reverse(cy.begin(), cy.end());

    cout << "YES\n";
    for(auto i: cy)
        cout << i + 1 << ' ';
}
