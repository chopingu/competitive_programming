class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> memo(n + 1);
        for(int i = 1; i <= n; i++) 
            memo[i] = memo[i >> 1] + (i & 1);

        return memo;
    }
};
