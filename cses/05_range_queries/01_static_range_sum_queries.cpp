#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> st(n + 1, vector<ll>(31));
    for(ll i = 0; i < n; i++)
        cin >> st[i][0];

    for(ll i = 1; i <= 30; i++) 
        for(ll j = 0; j + (1 << i) <= n; j++)
            st[j][i] += st[j][i - 1] + st[j + (1 << (i - 1))][i - 1];

    while(q--) {
        ll a, b;
        cin >> a >> b, --a, --b;

        ll sum = 0, len = b - a + 1;
        for(ll i = 30; i >= 0; i--) 
            if(len & (1 << i)) {
                sum += st[a][i];
                a += (1 << i);
            }

        cout << sum << '\n';
    }
}
