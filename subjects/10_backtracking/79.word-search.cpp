/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(backtracking(board, word, 0, i, j, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool backtracking(vector<vector<char>> &board, string word, int idx, int i, int j, int m, int n) {
        if(idx == word.size()) {
            return true;
        }
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }
        
        board[i][j] = '#';
        if(backtracking(board, word, idx+1, i+1, j, m, n) ||
           backtracking(board, word, idx+1, i-1, j, m, n) ||
           backtracking(board, word, idx+1, i, j+1, m, n) ||
           backtracking(board, word, idx+1, i, j-1, m, n)) {
            return true;
        }
        board[i][j] = word[idx];

        return false;
    }
};
// @lc code=end

