class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort nums
        sort(nums.begin(), nums.end());
        //result
        vector<vector<int>> result;
        set<vector<int>> s;
        //for i = 0 ~ num.size()-1
        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            if(first > 0) {
                break;
            }
            int l = i+1;
            int r = nums.size() - 1;
            int target = -nums[i];
            while(l < r) {
                if(nums[l] + nums[r] < target) {
                    l++;
                }
                else if(nums[l] + nums[r] == target) {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else{
                    r--;
                }
            }
        }
        for(vector<int> trip : s) {
            result.push_back(trip);
        }
        return result;
    }
};