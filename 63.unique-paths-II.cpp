class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        // for(int i = 0; i < m; i++) {
        //     if(obstacleGrid[i][0] == 1) {
        //         break;
        //     }
        //     dp[i][0] = 1;
        // }
        // for(int j = 0; j < n; j++) {
        //     if(obstacleGrid[0][j] == 1) {
        //         break;
        //     }
        //     dp[0][j] = 1;
        // }
        // for(int r = 1; r < m; r++) {
        //     for(int c = 1; c < n; c++) {
        //         dp[r][c] = dp[r-1][c] + dp[r][c-1];
        //     }
        // }
        // return dp[m-1][n-1];
        
        if(obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        obstacleGrid[m-1][n-1] = 1;
        for(int r = m-1; r >= 0; r--) {
            for(int c = n-1; c >= 0; c--) {
                if(r == m-1 && c == n-1) {
                    dp[r][c] = 1;
                }
                else if(obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0;
                }
                else{
                    dp[r][c] = dp[r+1][c] + dp[r][c+1];
                }
                
            }
            
        }
    
        return dp[0][0];
    }
};