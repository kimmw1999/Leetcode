class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        queue<int> not_unique;
        int result = 1;
        int i = 0;
        int j = 1;
        while(j < nums.size()) {
            if(nums[i] == nums[j]) {
                not_unique.push(j);
                j++;
            }
            else{
                if(!not_unique.empty()) {
                    int idx = not_unique.front();
                    not_unique.pop();
                    nums[idx] = nums[j];
                    not_unique.push(j);
                }
                i = j;
                j++;
                result++;
            }
        }
        return result;
    }
};