/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // for(int i = 0; i < matrix.size(); i++) {
        //     for(int j = i; j < matrix.size(); j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        //     reverse(matrix[i].begin(), matrix[i].end());
        // }
        int n = matrix.size();
        int l = 0;
        int r = n-1; 
        while(l < r) {
            for(int i = 0; i < r-l; i++) {
                int top = l;
                int bottom = r;
                int topleft = matrix[top][l+i];
                matrix[top][l+i] = matrix[bottom-i][l];
                matrix[bottom-i][l] = matrix[bottom][r-i];
                matrix[bottom][r-i] = matrix[top+i][r];
                matrix[top+i][r] = topleft;
            }
            r--;
            l++;
        }
    }
};
// @lc code=end

