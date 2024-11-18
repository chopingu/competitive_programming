#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(auto &i: a)
        cin >> i;

    ll id = 0, cur = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        cur += a[i];
        while(cur > x)
            cur -= a[id++];

        ans += (cur == x);
    }

    cout << ans;
}
