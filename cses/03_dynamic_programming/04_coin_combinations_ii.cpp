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

    const ll mod = 1e9 + 7;
    ll memo[x + 1]{};
    memo[0] = 1;
    for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < x + 1; j++)
            if(j + c[i] < x + 1)
                memo[j + c[i]] += memo[j], memo[j + c[i]] %= mod;

    cout << memo[x];

    /* TOO SLOW and TOO MUCH MEMORY CONSUMPTION
    const ll mod = 1e9 + 7;
    vector<vector<ll>> memo(n, vector<ll>(x + 1, -1));
    auto dp = [&](ll id, ll cur, auto&& dp) -> ll {
        if(id == n && !cur)
            return 1;

        if(id == n)
            return 0;

        ll &ans = memo[id][cur];
        if(ans ^ -1)
            return ans;

        ans = 0;
        for(ll i = 0; i <= cur / c[id]; i++) 
            ans += dp(id + 1, cur - i * c[id], dp), ans %= mod;

        return ans;
    };

    cout << dp(0, x, dp);
    */
}
