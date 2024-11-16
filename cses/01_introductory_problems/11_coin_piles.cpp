#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // x + 2y = a
    // 2x + y = b
    // 2a - b = 3y
    // 2b - a = 3x

    ll tc;
    cin >> tc;

    while(tc--) {
        ll a, b;
        cin >> a >> b;

        ll tmp1 = 2 * a - b, tmp2 = 2 * b - a;
        if(tmp1 < 0 || tmp2 < 0 || tmp1 % 3 || tmp2 % 3) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
