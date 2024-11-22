#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<array<ll, 2>>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        al[a].push_back({b, c});
    }

    vector<ll> cnt(n), ans;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 0});
    while(sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();

        if(cnt[u] == k)
            continue;

        if(u == n - 1)
            ans.push_back(d);

        cnt[u]++;
        for(auto [v, w]: al[u])
            pq.push({d + w, v});
    }

    for(auto i: ans)
        cout << i << ' ';
}
