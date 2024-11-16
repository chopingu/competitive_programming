#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll ans = 0, last = 0;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        ans += max(0ll, last - a);
        last = max(last, a);
    }

    cout << ans;
}
