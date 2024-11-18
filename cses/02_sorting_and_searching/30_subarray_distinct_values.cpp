#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    map<ll, ll> mp;
    ll ans = 0, id = 0;
    for(ll i = 0; i < n; i++) {
        mp[x[i]]++;
        while(sz(mp) > k) {
            if(!(--mp[x[id]]))
                mp.erase(x[id]);

            id++;
        }

        ans += i - id + 1;
    }

    cout << ans;
}
