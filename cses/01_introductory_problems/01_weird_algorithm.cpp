#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    while(n ^ 1) {
        cout << n << ' ';
        (n & 1) ? n = 3 * n + 1 : n /= 2;
    }

    cout << 1;
}
