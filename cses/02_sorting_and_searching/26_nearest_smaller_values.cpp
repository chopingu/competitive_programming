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

    vector<ll> ans(n, -1);
    stack<array<ll, 2>> s;
    for(ll i = n - 1; i >= 0; i--) {
        while(sz(s) && s.top()[0] > x[i])
            ans[s.top()[1]] = i, s.pop();

        s.push({x[i], i});
    }

    for(auto i: ans)
        cout << i + 1 << ' ';
}
