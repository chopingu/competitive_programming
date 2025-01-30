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

class Codec {
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        auto dfs1 = [&](TreeNode *u, auto&& dfs1) -> void {
            if(!u)
                return;

            ans += to_string(u->val);
            ans.push_back(',');
            dfs1(u->left, dfs1);
            dfs1(u->right, dfs1);
        };

        dfs1(root, dfs1);
        ans.push_back('|');

        auto dfs2 = [&](TreeNode *u, auto&& dfs2) -> void {
            if(!u)
                return;

            dfs2(u->left, dfs2);
            ans += to_string(u->val);
            ans.push_back(',');
            dfs2(u->right, dfs2);
        };

        dfs2(root, dfs2);

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preord, inord;
        string cur = "";
        int id = 0;
        while(id < data.size() && data[id] != '|') {
            if(data[id] == ',') {
                preord.push_back(stoi(cur));
                cur.clear();
                id++;
                continue;
            }
            cur.push_back(data[id++]);
        }

        id++;
        while(id < data.size()) {
            if(data[id] == ',') {
                inord.push_back(stoi(cur));
                cur.clear();
                id++;
                continue;
            }
            cur.push_back(data[id++]);
        }

        TreeNode *root = buildTree(preord, inord);
        return root;
    }
};
