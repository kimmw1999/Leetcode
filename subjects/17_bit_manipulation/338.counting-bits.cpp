class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for(int i = 0; i < n+1; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }   
        return result;
    }
};