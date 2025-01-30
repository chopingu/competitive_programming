class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> reach(n);
        for(int i = 0; i < n; i++)
            reach[i] = min(i + nums[i], n - 1);

        int id = 0;
        while(id < n - 1) {
            if(!nums[id])
                return false;

            if(reach[id] == n-1)
                return true;

            int mx = 0, it = 0;
            for(int i = id; i <= reach[id]; i++) {
                if(reach[i] >= mx) {
                    mx = reach[i];
                    it = i;
                }
            }

            id = it;
        }

        return true;
    }
};
