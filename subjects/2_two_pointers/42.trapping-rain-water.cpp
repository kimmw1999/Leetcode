/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxL = height[l];
        int maxR = height[r];
        int result = 0;
        while( l < r ) {
            if(height[l] <= height[r]){
                l++;
                maxL = max(maxL, height[l]);
                result += (maxL - height[l]);
            }
            else{
                r--;
                maxR = max(maxR, height[r]);
                result += (maxR - height[r]);
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,0};
    Solution sln;
    int ans = sln.trap(height);
}