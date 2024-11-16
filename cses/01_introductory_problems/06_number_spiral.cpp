#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc;
    cin >> tc;

    while(tc--) {
        ll y, x;
        cin >> y >> x;

        if(y >= x) {
            if(y & 1) {
                cout << y * y - 2 * y + 1 + x << '\n';
                continue;
            }

            cout << y * y - x + 1 << '\n';
            continue;
        }

        if(x & 1) {
            cout << x * x - y + 1 << '\n';
            continue;
        }

        cout << x * x - 2 * x + 1 + y << '\n';
    }
}
