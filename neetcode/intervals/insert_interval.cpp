class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool flag = true;
        vector<vector<int>> ans;
        for(auto inter: intervals) {
            if(inter[1] < newInterval[0] || inter[0] > newInterval[1]) {
                if(newInterval[1] < inter[0] && flag) 
                    ans.push_back(newInterval), flag = false;

                ans.push_back(inter);
                continue;
            }
            newInterval = {min(inter[0], newInterval[0]), max(inter[1], newInterval[1])};
        }
        if(flag) 
            ans.push_back(newInterval);

        return ans;
    }
};
