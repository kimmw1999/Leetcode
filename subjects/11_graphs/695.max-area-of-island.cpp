/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j, m, n));
                }
            }
        }
        
        return result;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        
        return 1 + dfs(grid, i - 1, j, m, n) + dfs(grid, i + 1, j, m, n)
            + dfs(grid, i, j - 1, m, n) + dfs(grid, i, j + 1, m, n);
    }
};

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int area;
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == 1) {
//                     area = 0;
//                     dfs(grid, i, j, m, n, area);
//                 }
//             }
//         }
//         return maxArea;
//     }
// private:
//     int maxArea = 0;
//     void dfs(vector<vector<int>> &grid, int r, int c, int m, int n, int &area) {
//         if(r < 0 || r >= m || c < 0 || c >= n) {
//             return;
//         }
//         if(grid[r][c] != 1) {
//             return;
//         }
//         area++;
//         if(area > maxArea) {
//             maxArea = area;
//         }
//         grid[r][c] = 0;
//         dfs(grid, r+1, c, m, n, area);
//         dfs(grid, r-1, c, m, n, area);
//         dfs(grid, r, c+1, m, n, area);
//         dfs(grid, r, c-1, m, n, area);
//     }
// };
// @lc code=end

