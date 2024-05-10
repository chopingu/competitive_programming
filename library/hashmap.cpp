#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    const uint64_t C=ll(2e18*acos(0))+71;
    const int RANDOM=chrono::high_resolution_clock::now().time_since_epoch().count();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
