#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll mx = 0, sum = 0;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        mx = max(mx, a);
        sum += a;
    }

    if(2 * mx >= sum) {
        cout << 2 * mx;
        return 0;
    }

    cout << sum;
}
