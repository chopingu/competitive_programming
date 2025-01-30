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
    bool isValidBST(TreeNode* root) {
        auto dfs = [](TreeNode *u, auto&& dfs) -> array<int, 3> {
            int mn = u->val, mx = u->val, flag = true;
            if(u->left) {
                auto res = dfs(u->left, dfs);
                mn = min(mn, res[0]);
                mx = max(mx, res[1]);
                flag &= res[2] & (res[1] < u->val);
            }
            if(u->right) {
                auto res = dfs(u->right, dfs);
                mn = min(mn, res[0]);
                mx = max(mx, res[1]);
                flag &= res[2] & (res[0] > u->val);
            }
            return {mn, mx, flag};
        };

        auto res = dfs(root, dfs);
        return res[2];
    }
};
