#pragma GCC optimize ("O3,inline")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    vector<vector<ll>> grid(9, vector<ll>(9));
    for(ll i = 0; i < 9; i++)
        grid[i][0] = grid[0][i] = grid[i][8] = grid[8][i] = 1;

    vector<int> dy = {-1, 0, 1, 0};
    vector<int> dx = {0, -1, 0, 1};
    unordered_map<char, ll> mp;
    mp['U'] = 0;
    mp['L'] = 1;
    mp['D'] = 2;
    mp['R'] = 3;

    ll ans = 0;
    auto rec = [&](ll y, ll x, ll id, auto&& rec) -> void {
        if(grid[y][x - 1] && grid[y][x + 1] && !grid[y + 1][x] && !grid[y - 1][x]) return;
        if(!grid[y][x - 1] && !grid[y][x + 1] && grid[y + 1][x] && grid[y - 1][x]) return;
        if(y == 7 && x == 1 && id == 48) {
            ans++;
            return;
        }
        if(y == 7 && x == 1) return;
        if(id == 48) return;

        grid[y][x] = 1;
        if(s[id] == '?') {
            for(ll d = 0; d < 4; d++) {
                ll y2 = y + dy[d], x2 = x + dx[d];
                if(!grid[y2][x2]) 
                    rec(y2, x2, id + 1, rec);
            }
        }
        else {
            ll d = mp[s[id]];
            ll y2 = y + dy[d], x2 = x + dx[d];
            if(!grid[y2][x2]) 
                rec(y2, x2, id + 1, rec);
        }

        grid[y][x] = 0;
    };

    rec(1, 1, 0, rec);

    cout << ans;
}
