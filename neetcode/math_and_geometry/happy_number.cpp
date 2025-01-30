class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis({n});
        while(n != 1) {
            int val = 0;
            while(n) {
                val += (n % 10) * (n % 10);
                n /= 10;
            }

            if(vis.find(val) != vis.end()) 
                return false;

            vis.insert(val);
            
            n = val;
        }

        return true;
    }
};
