/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <queue>
using namespace std;
#include <vector>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num:nums) {
            pq.push(num);
        }
        for(int i = 0; i < k-1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
// @lc code=end

