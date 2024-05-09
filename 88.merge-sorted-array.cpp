class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int curr = m + n - 1;
        while(curr >= 0) {
            if(i == -1) {
                nums1[curr] = nums2[j];
                j--;
            }
            else if(j == -1) {
                nums1[curr] = nums1[i];
                i--;
            }
            else{
                if(nums1[i] <= nums2[j]) {
                    nums1[curr] = nums2[j];
                    j--;
                }
                else{
                    nums1[curr] = nums1[i];
                    i--;
                }
            }
            curr--;
        }
        // vector temp(nums1.begin(), nums1.begin() + m);
        // for(int i = 0; i < m; i++) {
        //     temp[i] = nums1[i];
        // }
        // int i = 0;
        // int j = 0;
        // int curr = 0;
        // while(curr < m + n) {
        //     if(i == m) {
        //         nums1[curr] = nums2[j];
        //         j++;
        //     }
        //     else if(j == n) {
        //         nums1[curr] = temp[i];
        //         i++;
        //     }

        //     else{
        //         if(temp[i] < nums2[j]) {
        //             nums1[curr] = temp[i];
        //             i++;
        //         }
        //         else{
        //             nums1[curr] = nums2[j];
        //             j++;
        //         }
        //     }
        //     curr++;
        // }
    }
};