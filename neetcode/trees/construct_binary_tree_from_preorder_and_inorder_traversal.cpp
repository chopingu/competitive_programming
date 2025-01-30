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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return 0;

        int root = preorder[0];
        int id = find(inorder.begin(), inorder.end(), root) - inorder.begin();
        vector<int> lepre(preorder.begin() + 1, preorder.begin() + 1 + id);
        vector<int> ripre(preorder.begin() + 1 + id, preorder.end());
        vector<int> lein(inorder.begin(), inorder.begin() + id);
        vector<int> riin(inorder.begin() + id + 1, inorder.end());

        TreeNode *le = buildTree(lepre, lein);
        TreeNode *ri = buildTree(ripre, riin);
        
        return new TreeNode(root, le, ri);
    }
};
