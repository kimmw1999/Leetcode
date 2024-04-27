/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i = n-1; i > -1; i--) {
            for(string word: wordDict) {
                int n2 = word.size();
                if(i + n2 <= n && s.substr(i, n2) == word){
                    dp[i] = dp[i+n2];
                }
                if(dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }

};
// @lc code=end

