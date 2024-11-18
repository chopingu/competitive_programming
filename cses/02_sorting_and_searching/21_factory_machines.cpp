#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, t;
    cin >> n >> t;

    vector<ll> k(n);
    for(auto &i: k)
        cin >> i;

    ll lo = 0, hi = 1e18, ans = 0;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        ll cnt = 0;
        for(auto i: k) {
            cnt += mid / i;
            if(cnt >= t)
                break;
        }

        (cnt >= t) ? ans = mid, hi = mid - 1 : lo = mid + 1;
    }

    cout << ans;
}
