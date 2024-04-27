class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;


        vector<vector<int>> res(n, vector<int>(n));

        int count = 1;
        while(left <= right) {
            for(int j = left; j <= right; j++) {
                res[top][j] = count;
                count++;
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                res[i][right] = count;
                count++;
            }
            right--;
            if(top <= bottom) {
                for(int j = right; j >= left; j--) {
                    res[bottom][j] = count;
                    count++;
                }
                bottom--;
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    res[i][left] = count;
                    count++;
                }
                left++;
            }
        }

        return res;
    }
};