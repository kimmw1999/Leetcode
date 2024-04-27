/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtracking(result, curr, s, 0);
        return result;
    }

private:
    void backtracking(vector<vector<string>> &result, vector<string> &curr, string s, int start) {
        if(start == s.size()) {
            result.push_back(curr);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            if(is_palindrome(s, start, i)){
                string str = s.substr(start, i - start + 1);
                curr.push_back(str);
                backtracking(result, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }
    bool is_palindrome(string s, int i, int j) {
    
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

};
// @lc code=end

