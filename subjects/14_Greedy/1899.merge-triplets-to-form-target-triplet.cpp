/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

// @lc code=start
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> merged = {0, 0, 0};
        for(vector<int> tri : triplets) {
            int valid = true;
            for(int i = 0; i < 3; i++) {
                if(tri[i] > target[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                for(int i = 0; i < 3; i++) {
                    merged[i] = max(merged[i], tri[i]);
                }
            }
        }

        for(int i = 0; i < 3; i++) {
            if(merged[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

