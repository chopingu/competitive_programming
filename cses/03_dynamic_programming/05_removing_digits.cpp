#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll memo[n + 1];
    memset(memo, 0x3f, sizeof memo);
    memo[n] = 0;
    for(ll i = n; i >= 0; i--) {
        ll tmp = i;
        while(tmp) {
            ll dig = tmp % 10;
            tmp /= 10;

            memo[i - dig] = min(memo[i - dig], memo[i] + 1);
        }
    }

    cout << memo[0];
}
