class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> pos(26, -1);
        for(int i = 0; i < n; i++) 
            pos[s[i] - 'a'] = max(pos[s[i] - 'a'], i);

        vector<int> mx(n, -1);
        for(int i = 0; i < n; i++) {
            mx[i] = pos[s[i] - 'a'];
            if(i) mx[i] = max(mx[i], mx[i - 1]);
        }

        vector<int> ans;
        int id = 0;
        while(id != n) {
            int cnt = 1;
            do {
                cnt += mx[pos[s[id] - 'a']] - id, id = mx[pos[s[id] - 'a']];
            } while(mx[pos[s[id] - 'a']] != pos[s[id] - 'a']);

            ans.push_back(cnt);
            id++;
        }

        return ans;
    }
};
