#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    /*
    ll memo[n + 1];
    memset(memo, 0x3f, sizeof memo);
    memo[n] = 0;
    for(ll i = n; i >= 0; i--) {
        ll tmp = i;
        while(tmp) {
            ll dig = tmp % 10;
            tmp /= 10;

            memo[i - dig] = min(memo[i - dig], memo[i] + 1);
        }
    }

    cout << memo[0];
    */

    vector<ll> memo(n + 1, -1);
    auto dp = [&](ll cur, auto&& dp) -> ll {
        if(!cur)
            return 0;

        ll &ans = memo[cur];
        if(ans ^ -1)
            return ans;

        ans = 1e15;
        ll tmp = cur;
        while(tmp) {
            ll dig = tmp % 10;
            tmp /= 10;

            if(!dig) 
                continue;

            ans = min(ans, dp(cur - dig, dp) + 1);
        }

        return ans;
    };

    cout << dp(n, dp);
}
