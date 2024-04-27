/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> wordmap(26, -1);
        int len_s1 = s1.size();
        int len_s2 = s2.size();
        for(int i = 0; i < len_s1; i++) {
            if(wordmap[s1[i] - 'a'] == -1){
                wordmap[s1[i] - 'a'] = 0;
            }
            wordmap[s1[i] - 'a']++;
        }
        int i = 0;
        int j = 0;

        while(j < len_s2) {
            if(wordmap[s2[j] - 'a'] == -1) {//not valid char
                while(i < j){
                    wordmap[s2[i] - 'a']++;
                    i++;
                }
                i++;
                j++;
            }
            else if(wordmap[s2[j] - 'a'] == 0) {//used all char
                wordmap[s2[i] - 'a']++;
                i++;
            }
            else{
                wordmap[s2[j] - 'a']--;
                if(j-i+1 == len_s1) {
                    return true;
                }
                j++;
            }

        }
        return false;
    }
};
// @lc code=end
int main(){
    Solution solution;
    bool a = solution.checkInclusion("adc", "dcda");
}

