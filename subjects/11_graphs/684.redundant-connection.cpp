/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i < n+1; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }

        for(int i = 0; i < n; i++) {
            if(!union_graph(edges[i])){
                return edges[i];
            }
        }
        return {};

    }
private:
    vector<int> parent;
    vector<int> rank;
    int findParent(int n) {
        int p = n;
        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool union_graph(vector<int> edge) {
        
        int p1 = findParent(edge[0]);
        int p2 = findParent(edge[1]);
        if(p1 == p2) {
            return false;
        }
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
// @lc code=end

