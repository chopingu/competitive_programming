#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const ll mod = 1e9 + 7;
    const ll mxn = 1e6 + 5;

    ll memo[mxn + 1][6]{};
    memo[0][0] = memo[0][1] = 1;
    for(ll i = 1; i <= mxn; i++) {
        for(ll j = 0; j <= 1; j++)
            for(ll k = 0; k < 6; k++)
                memo[i][j] += memo[i - 1][k];

        for(ll j = 1; j <= 4; j++) {
            memo[i][2] += memo[i - 1][j];
            memo[i][3] += memo[i - 1][j];
            memo[i][4] += memo[i - 1][j];
        }

        memo[i][5] += memo[i - 1][0];
        memo[i][5] += memo[i - 1][5];

        for(ll j = 0; j < 6; j++)
            memo[i][j] %= mod;
    }

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        cout << memo[n][0] << '\n';
    }
}
