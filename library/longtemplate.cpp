#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T>
using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll rng(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

struct chash {
    const uint64_t C=ll(2e18*acos(0))+71;
    const int RANDOM=chrono::high_resolution_clock::now().time_since_epoch().count();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); }
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }

void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(bool x) { cerr << (x?"true":"false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {
    int f=0; 
    cerr << '{'; 
    for(auto &i: x) 
        cerr << (f++?", ":""), __print(i); 
    cerr << "}";
}
template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{'; 
    __print(x.first); 
    cerr << ", "; 
    __print(x.second); 
    cerr << '}';
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t); 
    if(sizeof...(v)) cerr << ", "; 
    _print(v...);
}

#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);

}
