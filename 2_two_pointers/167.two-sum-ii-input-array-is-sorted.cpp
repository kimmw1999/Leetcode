/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        int p1 = 0;
        int p2 = numbers.size() - 1;
        while(p1 < p2) {
            int sum = numbers[p1] + numbers[p2];
            if(sum == target) {
                output.push_back(p1+1);
                output.push_back(p2+1);
                return output;
            }
            else if(sum > target) {
                p2--;
            }
            else{
                p1++;
            }
        }
        return {0,0};
    }
};
// @lc code=end

