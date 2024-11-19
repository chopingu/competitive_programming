#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> w(n);
    for(auto &i: w)
        cin >> i;

    vector<array<ll, 2>> memo(1 << n, {(ll)1e9, (ll)1e9});
    memo[0] = {0, 0};
    for(ll i = 0; i < (1 << n); i++) {
        ll bitmask = i;
        while(bitmask) {
            ll j = (bitmask) & (-bitmask);
            ll k = __builtin_ctzll(j);
            if(w[k] + memo[i ^ j][1] <= x)
                memo[i] = min(memo[i], {memo[i ^ j][0], w[k] + memo[i ^ j][1]});
            else 
                memo[i] = min(memo[i], {memo[i ^ j][0] + 1, w[k]});

            bitmask ^= j;
        }
    }

    cout << memo[(1 << n) - 1][0] + !!memo[(1 << n) - 1][1];
}
