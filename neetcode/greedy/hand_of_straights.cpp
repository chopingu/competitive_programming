class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cnt;
        for(auto i: hand)
            cnt[i]++;

        while(!cnt.empty()) {
            int cur = cnt.begin()->first;
            cnt[cur]--;
            if(!cnt[cur])
                cnt.erase(cur);
                
            for(int i = 0; i < groupSize - 1; i++) {
                if(cnt.find(cur + 1) == cnt.end()) 
                    return false;

                cnt[cur + 1]--;
                if(!cnt[cur + 1])
                    cnt.erase(cur + 1);
                
                cur++;
            }
        }

        return true;
    }
};
