/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), square(9);
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') {
                    
                    continue;
                }

                if(row[r].find(board[r][c]) != row[r].end()) {
                    
                    return false;
                }
                if(col[c].find(board[r][c]) != col[r].end()) {
                    
                    return false;
                }
                int sq_idx = 3*(r/3) + c/3;
                if(square[sq_idx].find(board[r][c]) != square[sq_idx].end()) {
                    
                    return false;
                }
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                square[sq_idx].insert(board[r][c]);
            }
        }
        return true;
    }
};
// @lc code=end

