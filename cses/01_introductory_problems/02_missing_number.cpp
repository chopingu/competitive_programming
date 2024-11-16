#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll ans = n * (n + 1) / 2;
    for(ll i = 0; i < n - 1; i++) {
        ll a;
        cin >> a;

        ans -= a;
    }

    cout << ans;
}
