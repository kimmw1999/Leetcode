class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i = 0; i < intervals.size(); i++) {
            if(!rooms.empty()) {
                if(rooms.top() <= intervals[i][0]) {
                    rooms.pop();
                }    
            }
            rooms.push(intervals[i][1]);
        }
        return rooms.size();
    }
};