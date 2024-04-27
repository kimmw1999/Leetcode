/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for(int i = 0; i < t.size(); i++) {
            map[t[i]]++;
        }

        int i = 0;
        int j = 0;

        int counter = t.size();

        int minStart = 0;
        int minLength = INT_MAX;

        while(j < s.size()) {
            if (map[s[j]] > 0) {
                counter--;
            }

            map[s[j]]--;
            j++;

            while(counter == 0) {
                if(j - i < minLength) {
                    minStart = i;
                    minLength = j-i;
                }

                map[s[i]]++;

                if(map[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }
        if(minLength != INT_MAX){
            return s.substr(minStart, minLength);
        }
        return "";
    }
};
// @lc code=end