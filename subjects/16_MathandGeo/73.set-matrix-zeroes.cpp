/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((!visited[i][j] && matrix[i][j] == 0)) {
                    for(int r = 0; r < m; r++) {
                        if(matrix[r][j] != 0) {
                            matrix[r][j] = 0;
                            visited[r][j] = true;
                        }
                    }
                    for(int c = 0; c < n; c++) {
                        if(matrix[i][c] != 0) {
                            matrix[i][c] = 0;
                            visited[i][c] = true;
                        }
                    }
                }
            }
        }
    }
};
// @lc code=end

