#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << sz(ans) << '\n';
    for(auto i: ans)
        cout << i << '\n';
}
