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
}
