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

    const ll mod = 1e9 + 7;

    vector<ll> dist(n, 1e15), cnt(n), mn(n, 1e15), mx(n);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 0}); 
    dist[0] = 0, cnt[0] = 1, mn[0] = 0, mx[0] = 0;
    while(sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u])
            continue;

        for(auto [v, w]: al[u]) {
            if(dist[u] + w > dist[v]) continue;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.push({dist[v], v});
                continue;
            }
            cnt[v] += cnt[u], cnt[v] %= mod;
            mn[v] = min(mn[v], mn[u] + 1);
            mx[v] = max(mx[v], mx[u] + 1);
        }
    }

    cout << dist[n - 1] << ' ' << cnt[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1];
}
