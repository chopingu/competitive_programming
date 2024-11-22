#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    
    vector<vector<ll>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
    }

    const ll mod = 1e9 + 7;
    vector<ll> memo(n, -1);
    auto dp = [&](ll u, auto&& dp) -> ll {
        if(u == n - 1)
            return memo[u] = 1;
        
        ll &ans = memo[u];
        if(ans ^ -1) 
            return ans;

        ans = 0;
        for(auto v: al[u])
            ans += dp(v, dp), ans %= mod;

        return ans;
    };

    cout << dp(0, dp);
}
