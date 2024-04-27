/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i > -1; i--) {
            for(int j = n-1; j > -1; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

