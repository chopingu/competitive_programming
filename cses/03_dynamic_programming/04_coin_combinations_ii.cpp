#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> c(n);
    for(auto &i: c)
        cin >> i;

    const ll mod = 1e9 + 7;
    ll memo[x + 1]{};
    memo[0] = 1;
    for(ll i = 0; i < n; i++) 
        for(ll j = 0; j < x + 1; j++)
            if(j + c[i] < x + 1)
                memo[j + c[i]] += memo[j], memo[j + c[i]] %= mod;

    cout << memo[x];
}
