class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        vector<int> curr = intervals[0];
        while(i < intervals.size() - 1) {
            if(curr[1] >= intervals[i+1][0]) {
                curr[1] = max(curr[1], intervals[i+1][1]);
            }
            else{
                res.push_back(curr);
                curr = intervals[i+1];
                
            }
            i++;
        }
        res.push_back(curr);
        return res;
    }
};