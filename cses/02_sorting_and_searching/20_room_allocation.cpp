#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<array<ll, 3>> c;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        c.push_back({a, b, i});
    }
    sort(c.begin(), c.end());

    vector<ll> ans(n);
    set<array<ll, 2>> s;
    for(auto [a, b, id]: c) {
        auto it = s.lower_bound({a, (ll)-1e9});
        if(it == s.begin()) {
            ans[id] = sz(s) + 1;
            s.insert({b, sz(s)});
            continue;
        }
        --it;
        ll k = (*it)[1];
        s.erase(it);
        s.insert({b, k});
        ans[id] = k + 1;
    }

    ll mx = 0;
    for(auto i: ans)
        mx = max(mx, i);

    cout << mx << '\n';
    for(auto i: ans)
        cout << i << ' ';
}
