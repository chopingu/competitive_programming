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

    /* WITH PRIORITY QUEUE
    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 0});
    while(sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) 
            continue;

        for(auto [v, w]: al[u]) 
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }

    for(ll i = 0; i < n; i++) 
        cout << dist[i] << ' ';
    */

    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    set<array<ll, 2>> pq;
    for(ll i = 0; i < n; i++) 
        pq.insert({dist[i], i});

    while(sz(pq)) {
        auto [ign, u] = *pq.begin();
        pq.erase(pq.begin());

        for(auto [v, w]: al[u])
            if(dist[u] + w < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
    }

    for(ll i = 0; i < n; i++) 
        cout << dist[i] << ' ';
}
