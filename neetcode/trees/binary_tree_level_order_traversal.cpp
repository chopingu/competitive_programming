/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        auto dfs = [&](TreeNode *u, int depth, auto&& dfs) -> void {
            if(!u)
                return;
            
            if((int)(ans.size() - 1) < depth) 
                ans.push_back(vector<int>());
            
            ans[depth].push_back(u->val);
            dfs(u->left, depth + 1, dfs);
            dfs(u->right, depth + 1, dfs);
        };

        dfs(root, 0, dfs);
        
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> lvls = levelOrder(root);
        vector<int> ans;
        for(auto lvl: lvls)
            ans.push_back(lvl.back());

        return ans;
    }
};
