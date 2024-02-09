/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //1. unordered_map
        unordered_map<int, int> hashmap;

        for (int i : nums) {
            // Check if the current number already exists in the map
            if (hashmap.find(i) == hashmap.end()) {
                int left = hashmap.find(i - 1) != hashmap.end() ? hashmap[i - 1] : 0;
                int right = hashmap.find(i + 1) != hashmap.end() ? hashmap[i + 1] : 0;

                int length = left + right + 1;

                // Update the lengths for the boundaries of the consecutive sequence
                hashmap[i - left] = length;
                hashmap[i + right] = length;

                // Update the length for the current number itself
                hashmap[i] = length;
            }
        }

        int max_length = 0;
        for (const auto& pair : hashmap) {
            max_length = max(max_length, pair.second);
        }

        return max_length;
    }
};
// @lc code=end

