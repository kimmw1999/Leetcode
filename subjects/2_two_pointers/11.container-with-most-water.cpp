/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int j = n-1;
        int maxA = 0;
        int area;
        int smaller_height;
        while(i < j) {
            smaller_height = (height[i] > height[j])? j : i;
            area = (j - i) * height[smaller_height];
            if(area > maxA) {
                maxA = area;
            }

            if(smaller_height == i) {
                i++;
            }
            else{
                j--;
            }
        }
        return maxA;
    }
};
// @lc code=end

