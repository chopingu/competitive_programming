#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    /*
    const ll mod = 1e9 + 7;
    ll memo[n + 1]{};
    memo[0] = 1;
    for(ll i = 0; i < n + 1; i++) 
        for(ll j = 1; j <= 6; j++) 
            if(i + j < n + 1)
                memo[i + j] += memo[i], memo[i + j] %= mod;

    cout << memo[n];
    */

    const ll mod = 1e9 + 7;
    vector<ll> memo(n + 1, -1);
    auto dp = [&](ll cur, auto&& dp) -> ll {
        if(!cur)
            return 1;

        if(cur < 0)
            return 0;

        ll &ans = memo[cur];
        if(ans ^ -1)
            return ans;

        ans = 0;
        for(ll i = 1; i <= 6; i++) 
            ans += dp(cur - i, dp), ans %= mod;

        return ans;
    };

    cout << dp(n, dp);
}
