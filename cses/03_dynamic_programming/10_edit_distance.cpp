#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    ll n = sz(a);
    ll m = sz(b);

    ll memo[n + 1][m + 1];
    memset(memo, 0x3f, sizeof memo);
    memo[0][0] = 0;
    for(ll i = 0; i <= n; i++) 
        for(ll j = 0; j <= m; j++) {
            if(i) 
                memo[i][j] = min(memo[i][j], memo[i - 1][j] + 1);

            if(j)
                memo[i][j] = min(memo[i][j], memo[i][j - 1] + 1);

            if(i && j)
                memo[i][j] = min(memo[i][j], memo[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }

    cout << memo[n][m];
}
