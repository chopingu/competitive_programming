#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> am(n, vector<ll>(n));
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        am[a][b]++;
    }

    const ll mod = 1e9 + 7;

    /* BARELY FAST ENOUGH
    vector<vector<ll>> memo(n, vector<ll>(1 << n, -1));
    auto dp = [&](const ll u, const ll bitmask, auto&& dp) -> ll {
        if(u == n - 1 && !bitmask) 
            return 1;

        ll ans = memo[u][bitmask];
        if(ans ^ -1)
            return ans;

        ans = 0;
        ll tmp = bitmask;
        while(tmp) {
            ll lsb = tmp & -tmp;
            ll v = __builtin_ctzll(lsb);
            if(am[u][v])
                ans += am[u][v] * dp(v, bitmask ^ lsb, dp), ans %= mod;

            tmp ^= lsb;
        }

        return memo[u][bitmask] = ans;
    };

    cout << dp(0, ((1 << n) - 1) ^ 1, dp);
    */

    ll memo[1 << n][n]{};
    memo[((1 << n) - 1) ^ 1][0] = 1;
    for(ll i = (1 << n) - 1; i >= 0; i--) 
        for(ll j = 0; j < n; j++)
            if(!(i & (1 << j))) {
                ll bitmask = i;
                while(bitmask) {
                    ll k = bitmask & -bitmask;
                    ll l = __builtin_ctzll(k);
                    ll &tmp = memo[i ^ k][l];
                    tmp += am[j][l] * memo[i][j], tmp %= mod;
                    bitmask ^= k;
                }
            }

    cout << memo[0][n - 1];
}
