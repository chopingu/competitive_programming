#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    /*
    ll const mod = 1e9 + 7;
    vector<ll> memo(m + 2);
    if(!x[0]) {
        memo.assign(m + 2, 1);
        memo[0] = memo[m + 1] = 0;
    }
    else
        memo[x[0]] = 1;

    for(ll i = 1; i < n; i++) {
        vector<ll> nw_memo(m + 2);
        if(x[i]) {
           nw_memo[x[i]] += memo[x[i]] + memo[x[i] - 1] + memo[x[i] + 1]; 
           nw_memo[x[i]] %= mod;

           swap(memo, nw_memo);
           continue;
        }

        for(ll j = 1; j < m + 1; j++) {
            nw_memo[j] += memo[j - 1] + memo[j] + memo[j + 1];
            nw_memo[j] %= mod;
        }

        swap(memo, nw_memo);
    }

    ll ans = 0;
    for(auto i: memo)
        ans += i, ans %= mod;

    cout << ans;
    */

    const ll mod = 1e9 + 7;
    vector<vector<ll>> memo(n, vector<ll>(m + 1, -1));
    auto dp = [&](ll id, ll last, auto&& dp) -> ll {
        if(!last || last > m)
            return 0;

        if(id == n)
            return 1;

        if(x[id] && abs(last - x[id]) > 1) 
            return 0;

        ll &ans = memo[id][last];
        if(ans ^ -1)
            return ans;

        if(x[id])
            ans = dp(id + 1, x[id], dp);
        else
            ans = dp(id + 1, last - 1, dp) + dp(id + 1, last, dp) + dp(id + 1, last + 1, dp), ans %= mod;

        return ans;
    };

    ll ans = 0;
    if(x[0])
        ans = dp(1, x[0], dp);
    else {
        for(ll i = 1; i <= m; i++)
            ans += dp(1, i, dp), ans %= mod;
    }

    cout << ans;
}
