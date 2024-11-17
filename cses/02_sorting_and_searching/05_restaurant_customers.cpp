#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<array<int, 2>> t;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        t.push_back({a, 1});
        t.push_back({b, -1});
    }
    sort(t.begin(), t.end());

    ll ans = 0, cur;
    for(auto [ign, a]: t) 
        cur += a, ans = max(ans, cur);

    cout << ans;
}
