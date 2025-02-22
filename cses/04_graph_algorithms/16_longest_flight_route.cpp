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

    vector<ll> memo(n, -1);
    auto dp = [&](ll u, auto&& dp) -> ll {
        if(u == n - 1)
            return memo[u] = 1;
        
        ll &ans = memo[u];
        if(ans ^ -1)
            return ans;

        ans = -1e15;
        for(auto v: al[u])
            ans = max(ans, dp(v, dp));

        return ++ans;
    };

    if(dp(0, dp) < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    ll u = 0;
    vector<ll> pt({0});
    while(dp(u, dp) ^ 1) {
        for(auto v: al[u]) 
            if(dp(v, dp) == dp(u, dp) - 1) {
                u = v;
                break;
            }
        pt.push_back(u);
    }

    cout << sz(pt) << '\n';
    for(auto i: pt) 
        cout << i + 1 << ' ';
}
