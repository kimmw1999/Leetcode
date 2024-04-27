class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = r + dirs[i][0];
                int y = c + dirs[i][1];
                
                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] != INT_MAX) {
                    continue;
                }
                
                rooms[x][y] = rooms[r][c] + 1;
                q.push({x, y});
            }

        }
        
    }
};