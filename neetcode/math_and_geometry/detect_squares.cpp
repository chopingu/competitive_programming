class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    CountSquares() {}
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int y1 = point[1], x1 = point[0];

        for(auto a: cnt[x1]) {
            int y2 = a.first, tmp = a.second;
            int len = y2 - y1;
            if(!len) continue;

            int x3 = x1 + len, x4 = x1 - len;
            ans += tmp * cnt[x3][y1] * cnt[x3][y2];
            ans += tmp * cnt[x4][y1] * cnt[x4][y2];
        }

        return ans;
    }
};
