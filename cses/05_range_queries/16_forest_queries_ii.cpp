#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<string> grid(n);
    for(auto &i: grid)
        cin >> i;

    vector<vector<ll>> ft(n + 1, vector<ll>(n + 1)); 
    auto upd = [&](ll x, ll y, ll val) -> void {
        for(ll curx = x + 1; curx <= n; curx += curx & -curx)
            for(ll cury = y + 1; cury <= n; cury += cury & -cury)
                ft[curx][cury] += val;
    };

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            upd(j, i, (grid[i][j] == '*'));

    auto qry = [&](ll x, ll y) -> ll {
        ll ans = 0;
        for(ll curx = x + 1; curx; curx -= curx & -curx)
            for(ll cury = y + 1; cury; cury -= cury & -cury)
                ans += ft[curx][cury];

        return ans;
    };

    while(q--) {
        ll t;
        cin >> t, --t;

        if(!t) {
            ll y, x;
            cin >> y >> x, --y, --x;

            if(grid[y][x] == '*')
                upd(x, y, -1), grid[y][x] = '.';
            else
                upd(x, y, 1), grid[y][x] = '*';

            continue;
        }

        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2, --y1, --x1, --y2, --x2;

        cout << qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1) << '\n';
    }
}
