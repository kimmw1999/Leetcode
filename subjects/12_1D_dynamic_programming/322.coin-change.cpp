/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 0; i < amount+1; i++) {
            for(int c : coins) {
                if(i - c >= 0) {
                    dp[i] = min(1 + dp[i-c], dp[i]);
                }
            }
        }
        return dp[amount] == amount+1?  -1 : dp[amount];
    }
};
// @lc code=end

