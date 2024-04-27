class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bot = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> res;
        while(top <= bot && left <= right) {
            for(int c = left; c <= right; c++) {
                res.push_back(matrix[top][c]);
            }
            top++;
            for(int r = top; r <= bot; r++) {
                res.push_back(matrix[r][right]);
            }
            right--;
            if(top <= bot) {

                for(int c = right; c >= left; c--) {
                    res.push_back(matrix[bot][c]);
                }
            }
            bot--;
            if(left <= right) {
                for(int r = bot; r >= top; r--) {
                    res.push_back(matrix[r][left]);
                }
                left++;
            }
        }
        return res;
    
    }
};