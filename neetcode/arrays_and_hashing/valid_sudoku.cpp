#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<10> bs1, bs2;
        for(int i = 0; i < 9; i++) {
            bs1.reset();
            bs2.reset();
            for(int j = 0; j < 9; j++) {
                int ch1 = (board[i][j] == '.') ? 0 : board[i][j] - '0';
                int ch2 = (board[j][i] == '.') ? 0 : board[j][i] - '0';
                if(bs1[ch1] || bs2[ch2]) 
                    return false;
                else { 
                    bs1[ch1] = !!ch1;
                    bs2[ch2] = !!ch2;
                }
            }
        }

        bitset<10> bs;
        for(int i = 0; i < 9; i += 3) 
            for(int j = 0; j < 9; j += 3) {
                bs.reset();
                for(int dy = 0; dy < 3; dy++) 
                    for(int dx = 0; dx < 3; dx++) {
                        int ch = (board[i + dy][j + dx] == '.') ? 0 : board[i + dy][j + dx] - '0';
                        if(bs[ch])
                            return false;
                        else
                            bs[ch] = !!ch;
                    }
            }

        return true;
    }
};
