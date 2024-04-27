class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 1));
        for(int r = m-2; r >= 0; r--) {
            for(int c = n-2; c >= 0; c--) {
                memo[r][c] = memo[r+1][c] + memo[r][c+1];
            }
        }
        return memo[0][0];
        // return nCr(m-1 + n-1, n-1);
    }
private:
    int nCr(int n, int r) {
        if(r > n - r) {
            r = n - r;
        }

        long result = 1;
        //we want (n * (n-1) * (n-2) * ... * (n-r+1)) / (r * (r-1) * (r-2) * ... * 2 * 1);
        for(int i = 0; i < r; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    
};