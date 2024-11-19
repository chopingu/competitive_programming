#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    ll memo[a + 1][b + 1];
    memset(memo, 0x3f, sizeof memo);
    for(ll i = 1; i <= min(a, b); i++)
        memo[i][i] = 0;

    for(ll i = 1; i <= a; i++) 
        for(ll j = 1; j <= b; j++) {
            for(ll k = 1; k < i; k++) 
                memo[i][j] = min(memo[i][j], memo[k][j] + memo[i - k][j] + 1);

            for(ll k = 1; k < j; k++) 
                memo[i][j] = min(memo[i][j], memo[i][k] + memo[i][j - k] + 1);
        }

    cout << memo[a][b];
}
