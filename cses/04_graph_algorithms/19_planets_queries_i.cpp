#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    ll jmp[n][30];
    for(ll i = 0; i < n; i++)
        cin >> jmp[i][0], --jmp[i][0];

    for(ll i = 1; i < 30; i++) 
        for(ll j = 0; j < n; j++)
            jmp[j][i] = jmp[jmp[j][i - 1]][i - 1];

    while(q--) {
        ll x, k;
        cin >> x >> k, --x;

        for(ll i = 29; i >= 0; i--) 
            if(k & (1 << i))
                x = jmp[x][i];

        cout << x + 1 << '\n';
    }
}
