#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> id(n);
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a, --a;

        id[a] = i;
    }

    ll ans = 1; 
    for(ll i = 0; i < n - 1; i++) 
        ans += (id[i] > id[i + 1]);

    cout << ans;
}
