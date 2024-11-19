#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    ll memo[n][n];
    memset(memo, 0xc2, sizeof memo);
    for(ll i = 0; i < n; i++)
        memo[i][i] = x[i];

    for(ll i = n - 1; i >= 0; i--)
        for(ll j = i + 1; j < n; j++) {
            memo[i][j] = max(x[i] - memo[i + 1][j], x[j] - memo[i][j - 1]);
        }

    cout << (memo[0][n - 1] + accumulate(x.begin(), x.end(), 0ll)) / 2;
}
