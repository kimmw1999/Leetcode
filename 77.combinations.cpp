#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int>> ans;
        
        vector<int> curr;
        backtracking(ans, curr, 1);
        return ans;
    }

private:
    int n;
    int k;
    void backtracking(vector<vector<int>> &ans, vector<int> &curr, int firstNum) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int num = firstNum; num <= n; num++) {
            curr.push_back(num);
            backtracking(ans, curr, num+1);
            curr.pop_back();
        }
    }

};