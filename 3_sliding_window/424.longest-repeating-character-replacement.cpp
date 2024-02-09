/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0; //maximum length of substring
        unordered_map<char, int> hashmap; //key = letter, value = count
        int i = 0; 
        int j = 0;
        int maxCount = 0; //count the number of most major char in subarray
        int n = s.size();
        while(j < n){
            hashmap[s[j]]++;
            maxCount = max(maxCount, hashmap[s[j]]);//find the number of major char in subarray.
            if(j-i+1 - maxCount > k){
                //number of minor chars exceed k --> more than k chars changed.
                hashmap[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
// @lc code=end

