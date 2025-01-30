class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int dy[] = {0, 1, 0, -1};
        const int dx[] = {1, 0, -1, 0};
        vector<int> ans;
        int steps[] = {matrix[0].size(), matrix.size() - 1};

        int y = 0, x = -1, d = 0;
        while(steps[d % 2]) {
            for(int i = 0; i < steps[d % 2]; i++) {
                y += dy[d], x += dx[d];
                ans.push_back(matrix[y][x]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        
        return ans;
    }
};
