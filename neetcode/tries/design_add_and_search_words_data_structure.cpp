struct Node {
    int nxt[26], out;

    Node() : out(0) {
        memset(nxt, -1, sizeof nxt);
    }
};

class WordDictionary {
public:
    vector<Node> trie;

    WordDictionary() {
        trie.emplace_back();
    }
    
    void addWord(string word) {
        int id = 0;
        for(auto ch: word) {
            if(ch == '.') {

            }
            if(trie[id].nxt[ch - 'a'] == -1) {
                trie[id].nxt[ch - 'a'] = trie.size();
                trie.emplace_back();
            }
            id = trie[id].nxt[ch - 'a'];
        }
        trie[id].out = 1;
    }
    
    bool search(string word) {
        auto dfs = [&](int id1, int id2, auto&& dfs) -> int {
            if(id1 == -1)
                return 0;

            if(id2 == word.size()) 
                return trie[id1].out;

            if(word[id2] == '.') {
                int ans = 0;
                for(int i = 0; i < 26; i++) 
                    ans |= dfs(trie[id1].nxt[i], id2 + 1, dfs);

                return ans;
            }

            return dfs(trie[id1].nxt[word[id2] - 'a'], id2 + 1, dfs);
        };

        return dfs(0, 0, dfs);
    }
};
