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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        auto dfs = [&](TreeNode *u, int mx, auto&& dfs) -> void {
            if(!u) 
                return;
            
            cnt += (u->val >= mx);
            dfs(u->left, max(mx, u->val), dfs);
            dfs(u->right, max(mx, u->val), dfs);
        };

        dfs(root, -101, dfs);

        return cnt;
    }
};
