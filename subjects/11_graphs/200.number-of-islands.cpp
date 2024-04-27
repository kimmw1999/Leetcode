/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//leetcode solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    result++;
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == '1') {
//                     dfs(grid, i, j, m, n, 1);
//                 }
//             }
//         }
//         return result;
//     }


// private:
//     unordered_map<int, pair<int, int>> visited;
//     int result = 0;
//     void dfs(vector<vector<char>> &grid, int r, int c, int m, int n, int level) {
//         if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0' || 
//            visited.find(n*r+c) != visited.end()) {
//             return;
//         }

//         if(level == 1) {
//             result++;
//         }
//         visited[n*r+c] = {r,c};
//         vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
//         for(pair<int, int> dir : directions) {
//             dfs(grid, r+dir.first, c+dir.second, m, n, level + 1);
//         }
//     }
// };
// @lc code=end

