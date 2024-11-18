#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    ll mx = 0;
    vector<ll> x(n);
    for(auto &i: x)
        cin >> i, mx = max(mx, i);

    ll lo = mx, hi = 1e18, ans = 0;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        ll cur = 0, cnt = 1;
        for(auto i: x) {
            cur += i;
            if(cur > mid) {
                cur = i;
                cnt++;
            }
        }

        (cnt <= k) ? ans = mid, hi = mid - 1 : lo = mid + 1;
    }

    cout << ans;
}
