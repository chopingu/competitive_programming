#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll cur = 0, ans = 0, mx = -1e9;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        cur += a;
        if(cur < 0) 
            cur = 0;

        ans = max(ans, cur);
        mx = max(mx, a);
    }

    if(mx < 0) {
        cout << mx;
        return 0;
    }

    cout << ans;
}
