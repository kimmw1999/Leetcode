/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visited;
    }
};

// dfs
// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> m;
//         // build adjacency list of prereqs
//         for (int i = 0; i < prerequisites.size(); i++) {
//             m[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
//         unordered_set<int> visit;
//         unordered_set<int> cycle;
        
//         vector<int> result;
//         for (int course = 0; course < numCourses; course++) {
//             if (!dfs(course, m, visit, cycle, result)) {
//                 return {};
//             }
//         }
//         return result;
//     }
// private:
//     // a course has 3 possible states:
//     // visited -> course added to result
//     // visiting -> course not added to result, but added to cycle
//     // unvisited -> course not added to result or cycle
//     bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visit,
//         unordered_set<int>& cycle, vector<int>& result) {
        
//         if (cycle.find(course) != cycle.end()) {
//             return false;
//         }
//         if (visit.find(course) != visit.end()) {
//             return true;
//         }
//         cycle.insert(course);
//         for (int i = 0; i < m[course].size(); i++) {
//             int nextCourse = m[course][i];
//             if (!dfs(nextCourse, m, visit, cycle, result)) {
//                 return false;
//             }
//         }
//         cycle.erase(course);
//         visit.insert(course);
//         result.push_back(course);
//         return true;
//     }
// };
// @lc code=end

