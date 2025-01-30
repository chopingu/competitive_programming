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
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> subt;
        auto dfs1 = [&](TreeNode *u, auto&& dfs1) -> int {
            if(!u) 
                return 0;

            int le = dfs1(u->left, dfs1);
            int ri = dfs1(u->right, dfs1);

            return subt[u] = le + ri + 1;
        };

        dfs1(root, dfs1);

        auto dfs2 = [&](TreeNode* u, int k, auto&& dfs2) -> int {
            if(subt[u->left] + 1 == k) 
                return u->val;

            if(subt[u->left] >= k) 
                return dfs2(u->left, k, dfs2);

            return dfs2(u->right, k - subt[u->left] - 1, dfs2);
        };

        return dfs2(root, k, dfs2);
    }
};
