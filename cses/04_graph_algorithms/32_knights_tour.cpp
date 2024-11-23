#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll x, y;
    cin >> x >> y, --x, --y;

    const vector<ll> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    const vector<ll> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

    vector<vector<ll>> grid(8, vector<ll>(8));
    auto deg = [&](ll y, ll x) -> ll {
        ll deg = 0;
        for(ll i = 0; i < 8; i++) {
            ll y2 = y + dy[i], x2 = x + dx[i];
            if(y2 < 0 || y2 >= 8 || x2 < 0 || x2 >= 8) continue;
            if(grid[y2][x2]) continue;
            deg++;
        }

        return deg;
    };

    auto rec = [&](ll y, ll x, ll id, auto&& rec) -> ll {
        grid[y][x] = id;

        if(id == 64) 
            return 1;

        vector<array<ll, 3>> tmp;
        for(ll i = 0; i < 8; i++) {
            ll y2 = y + dy[i], x2 = x + dx[i];
            if(y2 < 0 || y2 >= 8 || x2 < 0 || x2 >= 8) continue;
            if(grid[y2][x2]) continue;
            tmp.push_back({deg(y2, x2), y2, x2});
        }
        sort(tmp.begin(), tmp.end());

        for(auto [d, y2, x2]: tmp)
            if(rec(y2, x2, id + 1, rec)) 
                return 1;

        grid[y][x] = 0;
        return 0;
    };

    rec(y, x, 1, rec);

    for(ll i = 0; i < 8; i++) {
        for(ll j = 0; j < 8; j++) 
            cout << grid[i][j] << ' ';
        
        cout << '\n';
    }
}
