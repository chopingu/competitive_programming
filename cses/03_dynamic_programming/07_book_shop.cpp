#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> h(n), s(n);
    for(auto &i: h)
        cin >> i;

    for(auto &i: s)
        cin >> i;

    vector<ll> memo(x + 1, -1);
    memo[0] = 0;
    for(ll i = 0; i < n; i++) {
        vector<ll> nw_memo = memo;
        nw_memo[0] = 0;
        for(ll j = x; j >= 0; j--)
            if(memo[j] ^ -1 && j + h[i] < x + 1)
                nw_memo[j + h[i]] = max(nw_memo[j + h[i]], memo[j] + s[i]);

        swap(memo, nw_memo);
    }

    ll ans = 0;
    for(auto i: memo)
        ans = max(ans, i);

    cout << ans;

    /* TOO MUCH MEMORY CONSUMPTION
    vector<vector<ll>> memo(n, vector<ll>(x + 1, -1));
    auto dp = [&](ll id, ll cur, auto&& dp) -> ll {
        if(cur < 0)
            return -1e15;

        if(id == n)
            return 0;

        ll &ans = memo[id][cur];
        if(ans ^ -1)
            return ans;

        return ans = max(dp(id + 1, cur - h[id], dp) + s[id], dp(id + 1, cur, dp));
    };

    cout << dp(0, x, dp);
    */
}
