class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = 0;
        int maxL = height[l];
        int maxR = height[r];
        while(l < r) {
            if(height[l] < height[r]) {
                l++;
                maxL = max(maxL, height[l]);
                area += (maxL - height[l]);
            }
            else{
                r--;
                maxR = max(maxR, height[r]);
                area += (maxR - height[r]);
            }
        }
        return area;
    }
};