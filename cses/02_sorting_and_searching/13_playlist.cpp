#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll id = 0, ans = 0;
    vector<ll> k;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        k.push_back(a);

        if(mp.find(a) != mp.end()) {
            ll tmp = mp[a];
            for(ll j = id; j <= tmp; j++) 
                mp.erase(k[j]);

            id = tmp + 1;
        }

        mp[a] = i;
        ans = max(ans, sz(mp));
    }

    cout << ans;
}
