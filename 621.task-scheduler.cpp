/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_count(26, 0);
        for(char ch : tasks) {
            task_count[ch - 'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int time = 0;
        for(int count : task_count) {
            if(count > 0) {
                pq.push(count);
            }
        }

        while(pq.size() > 0 || q.size() > 0) {
            int task;
            time++;
            if(!q.empty() && time > q.front().second) {
                pq.push(q.front().first);
                q.pop();
            } 
            if(!pq.empty()) {
                task = pq.top();
                pq.pop();
            }
            else{
                task = 0;
            }
            task--;
            if(task > 0) {
                q.push({task, time + n});
            }
        }
        return time;
    }
};
// @lc code=end

