/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int p = 0;
        int i = 0;
        int j = 0;
        int n = prices.size();
        while(j < n) {
            if(i == j) {
                j++;
            }
            else{
                if(prices[i] > prices[j]) {
                    i = j;
                    j++;
                }
                else{
                    p = prices[j] - prices[i];
                    if(maxP < p) {
                        maxP = p;
                    }
                    j++;
                }
            }
        }
        return maxP;
    }
};
// @lc code=end

