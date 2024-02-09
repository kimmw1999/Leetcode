/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start

#include <queue>
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        while(pq.size() > k) {
            pq.pop();
        } 
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > this->k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    int k;
    //to implement min heap. without greater --> max heap
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

