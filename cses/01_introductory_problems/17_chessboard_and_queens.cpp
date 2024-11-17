#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<string> grid(8);
    for(ll i = 0; i < 8; i++) 
        cin >> grid[i];

    ll ans = 0;
    bitset<15> row, di1, di2; 
    auto rec = [&](ll id, auto&& rec) -> void {
        if(id == 8) {
            ans++;
            return;
        }

        for(ll i = 0; i < 8; i++) {
            if(row[i] || di1[id + i] || di2[i - id + 7] || grid[i][id] == '*') continue;
            row[i] = di1[id + i] = di2[i - id + 7] = 1; 
            rec(id + 1, rec);
            row[i] = di1[id + i] = di2[i - id + 7] = 0; 
        }
    };

    rec(0, rec);

    cout << ans;
}
