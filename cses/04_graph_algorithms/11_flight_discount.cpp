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

    vector<array<ll, 2>> dist(n, {(ll)1e18, (ll)1e18});
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    while(sz(pq)) {
        auto [d, u, flag] = pq.top();
        pq.pop();

        if(d > dist[u][flag]) 
            continue;

        for(auto [v, w]: al[u]) {
            if(dist[v][flag] > dist[u][flag] + w) {
                dist[v][flag] = dist[u][flag] + w;
                pq.push({dist[v][flag], v, flag});
            }
            if(!flag && dist[v][1] > dist[u][0] + w / 2) {
                dist[v][1] = dist[u][0] + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n - 1][1];
}
