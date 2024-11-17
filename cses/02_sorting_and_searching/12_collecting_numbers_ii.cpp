#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> id(n), x(n);
    for(ll i = 0; i < n; i++) {
        ll &a = x[i];
        cin >> a, --a;

        id[a] = i;
    }

    ll ans = 1;
    for(ll i = 0; i < n - 1; i++)
        ans += (dp[i] > dp[i + 1]);

    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;
        
        if(a > b)
            swap(a, b);

        ans -= (
    }
}
