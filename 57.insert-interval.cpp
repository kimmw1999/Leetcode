class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool merged = false;
        for(vector<int> i : intervals) {
            if(merged) {
                res.push_back(i);
            }
            else{
                if(i[0] > newInterval[1]) {
                    res.push_back(newInterval);
                    res.push_back(i);
                    merged = true;
                }
                else if(i[1] < newInterval[0]) {
                    res.push_back(i);
                }
                else{
                    int start = min(i[0], newInterval[0]);
                    int end = max(i[1], newInterval[1]);
                    newInterval = {start, end};
                }
            }
        }
        if(!merged) {
            res.push_back(newInterval);
        }


        return res;
    }
};