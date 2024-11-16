#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll ans = 0, cur = 5;
    while(cur <= n) 
        ans += n / cur, cur *= 5;

    cout << ans;
}
