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
    ll memo[x + 1];
    memset(memo, 0x3f, sizeof memo);
    memo[0] = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < x + 1; j++)
            if(j + c[i] < x + 1)
                memo[j + c[i]] = min(memo[j + c[i]], memo[j] + 1);

    ll ans = (memo[x] > (ll)1e9) ? -1 : memo[x];
    cout << ans;
    */

    vector<ll> memo(x + 1, -1);
    auto dp = [&](ll cur, auto&& dp) -> ll {
        if(!cur)
            return 0;

        if(cur < 0)
            return 1e15;

        ll &ans = memo[cur];
        if(ans ^ -1)
            return ans;

        ans = 1e15;
        for(ll i = 0; i < n; i++)
            ans = min(ans, dp(cur - c[i], dp) + 1);

        return ans;
    };

    ll ans = (dp(x, dp) > 1e9) ? -1 : dp(x, dp);
    cout << ans;
}
