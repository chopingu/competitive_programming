#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll tot = 0;
    vector<int> p(n);
    for(auto &i: p)
        cin >> i, tot += i;

    ll ans = 1e18;
    for(ll i = 0; i < (1ll << n); i++) {
        ll cur = tot;
        for(ll j = 0; j < n; j++) 
            if(i & (1ll << j))
                cur -= 2 * p[j];

        ans = min(ans, abs(cur));
    }

    cout << ans;
}
