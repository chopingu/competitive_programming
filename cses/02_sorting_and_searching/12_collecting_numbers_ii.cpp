#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> pos(n), x(n);
    for(ll i = 0; i < n; i++) {
        ll &a = x[i];
        cin >> a, --a;

        pos[a] = i;
    }

    ll ans = 1;
    for(ll i = 0; i < n - 1; i++)
        ans += (pos[i] > pos[i + 1]);

    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        if(a > b) 
            swap(a, b);

        if(!(a ^ b)) {
            cout << ans << '\n';
            continue;
        }

        if(x[a] > x[b]) {
            if(x[a] < n - 1 && a < pos[x[a] + 1] && b > pos[x[a] + 1]) ++ans;
            if(x[b] && b > pos[x[b] - 1] && a < pos[x[b] - 1]) ++ans;
            if(x[a] - x[b] > 1 && b > pos[x[b] + 1] && a < pos[x[b] + 1]) --ans;
            if(x[a] - x[b] > 1 && a < pos[x[a] - 1] && b > pos[x[a] - 1]) --ans;
            if(x[a] == x[b] + 1) ans--;
        }

        if(x[a] < x[b]) {
            if(x[a] && a < pos[x[a] - 1] && b > pos[x[a] - 1]) --ans;
            if(x[b] < n - 1 && b > pos[x[b] + 1] && a < pos[x[b] + 1]) --ans;
            if(x[b] - x[a] > 1 && a < pos[x[a] + 1] && b > pos[x[a] + 1]) ++ans;
            if(x[b] - x[a] > 1 && b > pos[x[b] - 1] && a < pos[x[b] - 1]) ++ans;
            if(x[b] == x[a] + 1) ans++;
        }

        pos[x[a]] = b;
        pos[x[b]] = a;

        swap(x[a], x[b]);

        cout << ans << '\n';
    }
}
