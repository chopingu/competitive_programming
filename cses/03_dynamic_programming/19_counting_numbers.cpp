#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    auto cnt = [&](ll val) -> ll {
        vector<ll> digs;
        while(val) {
            digs.push_back(val % 10);
            val /= 10;
        }
        reverse(digs.begin(), digs.end());

        vector<vector<vector<vector<ll>>>> memo(sz(digs), vector<vector<vector<ll>>>(10, vector<vector<ll>>(2, vector<ll>(2, -1))));
        auto dp = [&](ll id, ll last, ll flag1, ll flag2, auto&& dp) -> ll {
            if(id == sz(digs))
                return 1;

            ll &ans = memo[id][last][flag1][flag2];
            if(ans ^ -1)
                return ans;

            ans = 0;
            if(flag2)
                ans += dp(id + 1, 0, 0, 1, dp);

            if(!flag1) {
                for(ll i = 0; i <= 9; i++) 
                    if(i ^ last)
                        ans += dp(id + 1, i, 0, 0, dp);

                return ans;
            }

            for(ll i = 0; i <= digs[id]; i++)
                if(i ^ last)
                    ans += dp(id + 1, i, (i == digs[id]), 0, dp);

            return ans;
        };

        return dp(0, 0, 1, 1, dp);
    };

    ll ans = cnt(b);
    if(a)
        ans -= cnt(a - 1);

    cout << ans;
}
