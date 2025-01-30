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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](TreeNode *u, auto&& dfs) -> int {
            if(!u)
                return 0;
            
            int le = dfs(u->left, dfs);
            int ri = dfs(u->right, dfs);

            ans = max(ans, le + ri);
            return max(le, ri) + 1;
        };

        dfs(root, dfs);

        return ans;
    }
};
