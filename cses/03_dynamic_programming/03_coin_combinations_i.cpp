#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> c(n);
    for(auto &i: c)
        cin >> i;

    /*
    const ll mod = 1e9 + 7;
    ll memo[x + 1]{};
    memo[0] = 1;
    for(ll i = 0; i < x + 1; i++) 
        for(ll j = 0; j < n; j++) 
            if(i + c[j] < x + 1)
                memo[i + c[j]] += memo[i], memo[i + c[j]] %= mod;

    cout << memo[x];
    */

    const ll mod = 1e9 + 7;
    vector<ll> memo(x + 1, -1);
    auto dp = [&](ll cur, auto&& dp) -> ll {
        if(!cur)
            return 1;

        if(cur < 0)
            return 0;

        ll &ans = memo[cur];
        if(ans ^ -1)
            return ans;

        ans = 0;
        for(ll i = 0; i < n; i++)
            ans += dp(cur - c[i], dp), ans %= mod;

        return ans;
    };

    cout << dp(x, dp);
}
