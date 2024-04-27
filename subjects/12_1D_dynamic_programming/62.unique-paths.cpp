/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for(int r = m-2; r > -1; r--) {
            for(int c = n-2; c > -1; c--) {
                grid[r][c] = grid[r+1][c] + grid[r][c+1];
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

