#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    vector<array<ll, 2>> m;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        m.push_back({b, a});
    }
    sort(m.begin(), m.end());

    ll ans = 0;
    multiset<ll> ms;
    for(auto [b, a]: m) {
        auto it = ms.upper_bound(a);
        if(it == ms.begin()) {
            if(sz(ms) < k) {
                ms.insert(b);
                ans++;
            }
            continue;
        }

        --it, ans++;
        ms.erase(it);
        ms.insert(b);
    }

    cout << ans;
}
