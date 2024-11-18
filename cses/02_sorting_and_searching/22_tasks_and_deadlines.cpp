#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<array<ll, 2>> t;
    for(ll i = 0; i < n; i++) {
        ll a, d;
        cin >> a >> d;

        t.push_back({a, d});
    }
    sort(t.begin(), t.end());

    ll ans = 0, cur = 0;
    for(auto [a, d]: t) 
        cur += a, ans += d - cur;

    cout << ans;
}
