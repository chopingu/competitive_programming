#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<vector<ll>> memo(n, vector<ll>(2, -1));
    auto dp = [&](ll u, ll flag, ll p, auto&& dp) -> ll {
        ll &ans = memo[u][flag];
        if(ans ^ -1)
            return ans;

        ans = 0;
        if(flag) {
            for(auto v: al[u])
                if(v ^ p)
                    ans += dp(v, 0, u, dp);

            return ans;
        }

        ll mx = -1e9;
        for(auto v: al[u])
            if(v ^ p) {
                ans += dp(v, 0, u, dp);
                mx = max(mx, dp(v, 1, u, dp) - dp(v, 0, u, dp));
            }

        ans = max(ans, ans + mx + 1);

        return ans;
    };

    cout << dp(0, 0, -1, dp);
}
