#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    ll k = 0;
    vector<ll> memo(n, -1);
    for(ll i = 0; i < n; i++) {
        int id = lower_bound(memo.begin(), memo.begin() + k, x[i]) - memo.begin();
        memo[id] = x[i];
        k += (id == k);
    }

    cout << k;
}
