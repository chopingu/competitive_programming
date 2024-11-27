#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> ft(n + 1, vector<ll>(n + 1));
    auto upd = [&](ll x, ll y, ll val) -> void {
        for(; x <= n; x += x & -x)
            for(ll i = y; i <= n; i += i & -i)
                ft[x][i] += val;
    };

    auto qry = [&](ll x, ll y1, ll y2) -> ll {
        ll ans = 0;
        for(; x; x -= x & -x) {
            for(ll i = y2; i; i -= i & -i)
                ans += ft[x][i];

            for(ll i = y1 - 1; i; i -= i & -i)
                ans -= ft[x][i];
        }

        return ans;
    };

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) {
            char a;
            cin >> a;

            upd(j + 1, i + 1, (a == '*'));
        }

    while(q--) {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << qry(x2, y1, y2) - qry(x1 - 1, y1, y2) << '\n';
    }
}
