#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> memo(n, vector<ll>(n, 1e18));
    for(ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;

        memo[a][b] = memo[b][a] = min(memo[a][b], c);
    }
    for(ll i = 0; i < n; i++) 
        memo[i][i] = 0;

    for(ll k = 0; k < n; k++)
        for(ll i = 0; i < n; i++) 
            for(ll j = 0; j < n; j++) 
                if(memo[i][k] < 1e18 && memo[k][j] < 1e18)
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);

    while(q--) {
        ll a, b;
        cin >> a >> b, --a, --b;

        if(memo[a][b] == 1e18)
            cout << "-1\n";
        else
            cout << memo[a][b] << '\n';
    }
}
