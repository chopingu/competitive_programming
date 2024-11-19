#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    if((n * (n + 1) / 2) & 1) {
        cout << 0;
        return 0;
    }

    const ll mod = 1e9 + 7;
    vector<ll> memo(n * (n + 1) / 4 + 1);
    memo[0] = 1;
    for(ll i = 1; i <= n; i++) {
        vector<ll> nw_memo = memo;
        for(ll j = n * (n + 1) / 4 - i; j >= 0; j--) 
            nw_memo[j + i] += memo[j], nw_memo[j + i] %= mod;

        swap(memo, nw_memo);
    }

    auto xgcd = [&](ll a, ll b, auto&& xgcd) -> array<ll, 3> {
        if(!a)
            return {b, 0, 1};

        auto [gcd, x1, y1] = xgcd(b % a, a, xgcd);
        ll x2 = y1 - x1 * (b / a);
        ll y2 = x1;

        return {gcd, x2, y2};
    };

    cout << (memo[n * (n + 1) / 4] * xgcd(2, mod, xgcd)[1] % mod + mod) % mod;
}
