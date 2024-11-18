#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    map<ll, ll> mp;
    mp[0] = 1;
    ll cur = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        cur += a, cur = (cur % n + n) % n;
        ans += mp[cur];
        mp[cur]++;
    }

    cout << ans;
}
