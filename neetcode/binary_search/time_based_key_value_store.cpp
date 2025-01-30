#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& a = mp[key];

        int lo = 0, hi = a.size() - 1, ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            (a[mid].first <= timestamp) ? ans = mid, lo = mid + 1 : hi = mid - 1;
        }

        return (ans != -1) ? a[ans].second : "";
    }
};
