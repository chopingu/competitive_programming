class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!matrix[i][j]) {
                    matrix[0][j] = 0;
                    if(i) 
                        matrix[i][0] = 0;
                    else
                        flag = 1;
                }

        for(int i = 1; i < n; i++) 
            for(int j = 1; j < m; j++)
                if(!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;

        if(!matrix[0][0])
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
    
        if(flag) 
            for(int i = 0; i < m; i++) 
                matrix[0][i] = 0;
    }
};
