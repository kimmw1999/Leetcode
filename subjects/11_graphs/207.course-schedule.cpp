/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
//dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, graph, visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited) {
        if(visited.find(course) != visited.end()) {
            return false;
        }
        if(graph[course].empty()) {
            return true;
        }
        visited.insert(course);
        for(int i = 0; i < graph[course].size(); i++) {
            int next_course = graph[course][i];
            if(!dfs(next_course, graph, visited)) {
                return false;
            }
        }
        graph[course].clear();
        visited.erase(course);
        return true;
    }
};
// @lc code=end

