/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = m-1;
        int bot = n-1;
        int top = 0;
        while(l <= r && top <= bot) {
            for(int i = l; i <= r; i++) {
                output.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bot; i++) {
                output.push_back(matrix[i][r]);
            }
            r--;
            if(top <= bot) {
                for(int i = r; i >= l; i--) {
                    output.push_back(matrix[bot][i]);
                }
            }
            bot--;
            if(l <= r) {
                for(int i = bot; i >= top; i--) {
                    output.push_back(matrix[i][l]);
                }

            }
            l++;
        }
        return output;
    }
};
// @lc code=end

