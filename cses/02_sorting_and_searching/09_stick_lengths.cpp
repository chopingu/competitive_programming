#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for(auto &i: a)
        cin >> i;

    sort(a.begin(), a.end());

    ll ans = 0;
    for(ll i = 0; i < n; i++) 
        ans += abs(a[n / 2] - a[i]);

    cout << ans;
}
