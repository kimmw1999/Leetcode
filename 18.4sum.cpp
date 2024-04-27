#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sort nums
        sort(nums.begin(), nums.end());

        // Result
        if(nums.size() < 4) {
            return {};
        }

        vector<vector<int>> result;
        set<vector<int>> s;

        for(int i = 0; i < nums.size() - 3; i++) {
            for(int j = i + 1; j < nums.size() - 2; j++) {
                // Safeguard against integer overflow
                long long first = nums[i];
                long long second = nums[j];
                if(first > 0 && first + second > target) {
                    break;
                }

                int l = j + 1;
                int r = nums.size() - 1;

                while(l < r) {
                    // Use long long for sum to prevent overflow
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[l] + nums[r];

                    if(sum < target) {
                        l++;
                    } else if(sum == target) {
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    } else {
                        r--;
                    }
                }
            }
        }

        for(const vector<int>& vec : s) {
            result.push_back(vec);
        }

        return result;
    }
};
