class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = m + n;
        int l = 0;
        int r = m;
        while(l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = (total + 1)/ 2 - mid1;
            int l1 = (mid1 > 0) ? nums1[mid1-1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2-1] : INT_MIN;
            int r1 = (mid1 < m) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                if(total % 2 == 1) {
                    result = max(l1, l2);
                }
                else{
                    result = (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                break;
            }
            else if(l1 > r2) {
                r = mid1 - 1;
            }
            else {
                l = mid1 + 1;
            }
        }
        return result;
        
    }
};