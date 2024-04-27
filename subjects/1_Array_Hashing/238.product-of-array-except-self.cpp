/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start

//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        int counter = 1;
        for(int i = 1; i < n; i++) {
            counter = counter * nums[i-1];
            output[i] = counter;
        }
        counter = 1;
        for(int i = 1; i < n; i++) {
            counter = counter * nums[n-i];
            output[n-1-i] = output[n-1-i] * counter;
        }
        return output;
    }
private:
    vector<int> solution1(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> output;

        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
            right[n-1-i] = right[n-i] * nums[n-i];
        }
        for(int i = 0; i < n; i++) {
            output.push_back(left[i] * right[i]);
        }
        return output;
    }

    vector<int> solution2(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        int counter = 1;
        for(int i = 1; i < n; i++) {
            counter = counter * nums[i-1];
            output[i] = counter;
        }
        counter = 1;
        for(int i = 1; i < n; i++) {
            counter = counter * nums[n-i];
            output[n-1-i] = output[n-1-i] * counter;
        }
        return output;
    }
};
// @lc code=end

