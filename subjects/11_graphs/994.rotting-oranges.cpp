/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        q.push({-1, -1});
        int result = -1;
        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r==-1) {
                result++;
                if(!q.empty()) {
                    q.push({-1, -1});
                }
            }
            else{
                //rotten orange contaminates
                for(pair<int, int> dir : directions) {
                    int x = r + dir.first;
                    int y = c + dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if(grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
        }

        if(fresh == 0) {
            return result;
        }
        return -1;
    }
};
// @lc code=end

