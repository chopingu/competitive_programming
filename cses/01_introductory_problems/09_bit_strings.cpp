#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    const ll mod = 1e9 + 7;
    ll ans = 1, base = 2;
    while(n) {
        if(n & 1) 
            ans *= base, ans %= mod;

        base *= base;
        base %= mod;
        
        n >>= 1;
    }
    
    cout << ans;
}
