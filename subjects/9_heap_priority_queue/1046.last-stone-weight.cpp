/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
#include <queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while(pq.size() > 1) {
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            if(st1 > st2) {
                st1 = st1 - st2;
                pq.push(st1);
            }
        }

        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};
// @lc code=end

