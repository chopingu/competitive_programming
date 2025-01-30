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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        auto dfs = [&](TreeNode *u, auto &&dfs) -> int {
            if(!u) 
                return 0;
            
            int le = dfs(u->left, dfs);
            int ri = dfs(u->right, dfs);

            ans &= (abs(le - ri) <= 1);
            return max(le, ri) + 1;
        };

        dfs(root, dfs);

        return ans;
    }
};
