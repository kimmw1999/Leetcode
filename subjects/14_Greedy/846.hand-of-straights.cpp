/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for(int i = 0; i < hand.size(); i++) {
            m[hand[i]]++;
        }
        while(!m.empty()) {
            int min_val = m.begin()->first;
            for(int i = 0; i < groupSize;i++) {
                if(m[min_val+i] == 0) {
                    return false;
                }
                m[min_val+i]--;
                if(m[min_val+i] == 0) {
                    m.erase(min_val + i);
                }
            }
        }
        return true;
    }
};
// @lc code=end

