#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll q;
    cin >> q;

    while(q--) {
        ll k;
        cin >> k, --k;

        ll dig = 1, cur = 1;
        while(k - dig * 9 * cur >= 0) {
            k -= dig * 9 * cur;
            dig++;
            cur *= 10;
        }

        cur += k / dig;
        k -= k / dig * dig;

        cout << to_string(cur)[k] << '\n';
    }
}
