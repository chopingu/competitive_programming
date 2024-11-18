#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<string> grid(n);
    for(auto &i: grid)
        cin >> i;

    vector<ll> dy = {0, 1};
    vector<ll> dx = {1, 0};

    ll const mod = 1e9 + 7;
    ll memo[n][n]{};
    memo[0][0] = (grid[0][0] != '*');
    for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < n; j++)
            for(ll k = 0; k < 2; k++) {
                ll y = i + dy[k], x = j + dx[k];
                if(y >= n || x >= n || grid[y][x] == '*') continue;
                memo[y][x] += memo[i][j];
                memo[y][x] %= mod;
            }

    cout << memo[n - 1][n - 1];
}
