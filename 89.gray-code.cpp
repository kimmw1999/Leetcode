class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        makeGrayCode(n, 0, ans);
        return ans;
    }

    void makeGrayCode(int n, int k, vector<int> &ans) {
        if(k == n) {
            return;
        }

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans.push_back(ans[i] + (1 << k));
        }

        makeGrayCode(n, k+1, ans);
    }
};