class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minS = INT_MAX;
        int minDist = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            int l = i+1;
            int r = nums.size() - 1;
            while(l < r) {
                int s = nums[i] + nums[l] + nums[r];
                int dist = abs(target - s);
                if(minDist > dist) {
                    minS = s;
                    minDist = dist;
                }
                if(s > target) {
                    r--;
                }
                else if(s < target) {
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        return minS;
    }
};