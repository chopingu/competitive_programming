#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    const ll mod = 1e9 + 7;
    ll memo[n + 1]{};
    memo[0] = 1;
    for(ll i = 0; i < n + 1; i++) 
        for(ll j = 1; j <= 6; j++) 
            if(i + j < n + 1)
                memo[i + j] += memo[i], memo[i + j] %= mod;

    cout << memo[n];
}
