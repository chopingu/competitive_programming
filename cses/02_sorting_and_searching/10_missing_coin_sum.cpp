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

    sort(x.begin(), x.end());

    ll ans = 1;
    for(auto i: x)
        if(i <= ans)
            ans += i;

    cout << ans;
}
