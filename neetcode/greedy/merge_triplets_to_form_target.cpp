class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3);
        for(auto tr: triplets) {
            int flag = 1;
            for(int i = 0; i < 3; i++)
                flag &= (tr[i] <= target[i]);
            
            if(!flag) 
                continue;
            
            for(int i = 0; i < 3; i++)
                ans[i] |= (tr[i] == target[i]);
        }

        int ans2 = ans[0] & ans[1] & ans[2];
        return ans2;
    }
};
