#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    ll last = -1, cur = 0, ans = 0;
    for(auto ch: s) 
        if(ch - 'A' == last) 
            cur++, ans = max(ans, cur);
        else 
            last = ch - 'A', cur = 1, ans = max(ans, cur);

    cout << ans;
}
