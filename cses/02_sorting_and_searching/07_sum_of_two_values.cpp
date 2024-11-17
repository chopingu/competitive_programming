#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        if(mp.find(x - a) != mp.end()) {
            cout << mp[x - a] << ' ' << i + 1 << '\n';
            return 0;
        }

        mp[a] = i + 1;
    }

    cout << "IMPOSSIBLE";
}
