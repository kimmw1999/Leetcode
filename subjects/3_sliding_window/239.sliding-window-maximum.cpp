/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        deque<int> dq;
        vector<int> result;
        int n = nums.size();
        while(j < n) {
            while(!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();//make deque elements decreasing order
            }
            dq.push_back(j);

            if (i > dq.front()) {
                //deque stores indecies. now out of range.
                dq.pop_front();
            }

            if (j+1 >= k) {
                //checking if sliding window size is equal to k. counting starts from j+1
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return result;
    }
};
// @lc code=end

