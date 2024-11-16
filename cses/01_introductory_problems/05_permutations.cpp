#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    if(n == 1) {
        cout << 1;
        return 0;
    }

    if(n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    for(ll i = 1; i <= n / 2; i++) 
        cout << 2 * i << ' ';

    for(ll i = 0; i < (n + 1) / 2; i++) 
        cout << 2 * i + 1 << ' ';
}
