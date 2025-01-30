class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<array<int, 2>> ints;
        for(auto a: intervals) 
            ints.push_back({a[0], -a[1]});
        
        vector<vector<int>> ans;
        sort(ints.begin(), ints.end());
        for(int i = 0; i < ints.size(); i++) {
            int a = ints[i][0], b = -ints[i][1];
            int id = i + 1;
            while(id < ints.size() && ints[id][0] <= b) 
                b = max(b, -ints[id][1]), id++;
            
            ans.push_back({a, b});
            i = id - 1;
        }

        return ans;
    }
};
