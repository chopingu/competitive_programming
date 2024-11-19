#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> t;
    vector<array<ll, 3>> pr;
    for(ll i = 0; i < n; i++) {
        ll a, b, p;
        cin >> a >> b >> p;

        t.push_back(a);
        t.push_back(b);
        pr.push_back({a, b, p});
    }
    sort(t.begin(), t.end());

    map<ll, ll> comp;
    for(auto i: t)
        if(comp.find(i) == comp.end())
            comp[i] = sz(comp);

    n = sz(comp);
    vector<vector<array<ll, 2>>> al(n + 2, vector<array<ll, 2>>());
    for(auto [a, b, p]: pr)
        al[comp[a]].push_back({comp[b], p});

    ll memo[n + 2]{};
    for(ll i = 0; i <= n; i++) {
        for(auto [b, p]: al[i])
            memo[b + 1] = max(memo[b + 1], memo[i] + p);

        memo[i + 1] = max(memo[i + 1], memo[i]);
    }

    cout << memo[n + 1];
}
