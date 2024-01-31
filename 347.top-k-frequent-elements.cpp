/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it = hashmap.begin(); it != hashmap.end(); it++) {
            pq.push({it->second, it->first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> output;
        while(!pq.empty()) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;

    }
};
// @lc code=end

