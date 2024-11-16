#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    vector<int> cnt(26);
    for(auto ch: s)
        cnt[ch - 'A']++;

    ll id = -1;
    for(ll i = 0; i < 26; i++) 
        if(cnt[i] & 1) {
            if(id ^ -1) {
                cout << "NO SOLUTION";
                return 0;
            }
            id = i;
        }

    deque<int> dq;
    if(id ^ -1) 
        dq.push_back(id), cnt[id]--;

    for(ll i = 0; i < 26; i++) 
        for(ll j = 0; j < cnt[i] / 2; j++) {
            dq.push_back(i);
            dq.push_front(i);
        }

    for(auto i: dq)
        cout << (char)(i + 'A'); 
}
