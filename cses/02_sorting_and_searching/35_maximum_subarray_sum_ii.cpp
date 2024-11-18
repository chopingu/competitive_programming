#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> pre(n + 1);
    for(ll i = 0; i < n; i++)
        cin >> pre[i + 1], pre[i + 1] += pre[i];

    ll ans = -1e18;
    multiset<ll> ms;
    for(ll i = 1; i <= n; i++) {
        if(i > b) 
            ms.erase(ms.find(pre[i - b - 1]));

        if(i >= a) {
            ms.insert(pre[i - a]);
            ans = max(ans, pre[i] - *ms.begin());
        }
    }

    cout << ans;
}
