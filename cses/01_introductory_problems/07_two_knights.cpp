#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) 
        cout << i * i * (i * i - 1) / 2 - 2 * (i - 2) * (i - 1) * 2 << '\n';
}
