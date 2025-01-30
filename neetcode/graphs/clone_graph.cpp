/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return 0;

        unordered_map<Node*, Node*> vis;
        auto dfs = [&](Node *u, auto&& dfs) -> void {
            vis[u] = new Node(u->val);
            for(auto v: u->neighbors) {
                if(vis.find(v) == vis.end()) 
                    dfs(v, dfs);
                
                vis[u]->neighbors.push_back(vis[v]);
            }
        };

        dfs(node, dfs);

        return vis[node];
    }
};
