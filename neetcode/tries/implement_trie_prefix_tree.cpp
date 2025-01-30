struct Node {
    int next[26];
    bool output;

    Node() : output(false) {
        memset(next, -1, sizeof next);
    }
};

class PrefixTree {
public:
    vector<Node> trie;

    PrefixTree() {
        trie.emplace_back();
    }
    
    void insert(string word) {
        int id = 0;
        for(auto ch: word) {
            if(trie[id].next[ch - 'a'] == -1) {
                trie[id].next[ch - 'a'] = trie.size();
                trie.emplace_back();
            }
            id = trie[id].next[ch - 'a'];
        }
        trie[id].output = true;
    }
    
    bool search(string word) {
        int id = 0;
        for(auto ch: word) {
            if(trie[id].next[ch - 'a'] == -1) 
                return false;

            id = trie[id].next[ch - 'a'];
        }
        return trie[id].output;
    }
    
    bool startsWith(string prefix) {
        int id = 0;
        for(auto ch: prefix) {
            if(trie[id].next[ch - 'a'] == -1) 
                return false;

            id = trie[id].next[ch - 'a'];
        }
        return true;
    }
};

