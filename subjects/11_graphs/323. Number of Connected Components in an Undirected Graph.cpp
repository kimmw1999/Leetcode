//leetcode
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents;
        vector<int> ranks;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(1);
        }
        
        int result = n;
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            result -= doUnion(parents, ranks, n1, n2);
        }
        return result;
    }
private:
    int doFind(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    
    int doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = doFind(parents, n1);
        int p2 = doFind(parents, n2);
        if (p1 == p2) {
            return 0;
        }
        
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        
        return 1;
    }
};



// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<bool> visited;
//         unordered_map<int, vector<int>> map;
//         for(int i = 0; i < n; i++) {
//             visited.push_back(false);
//         }
//         for(int i = 0; i < edges.size(); i++) {
//             map[edges[i][0]].push_back(edges[i][1]);
//             map[edges[i][1]].push_back(edges[i][0]);
//         }

//         int result = 0;
//         for(int i = 0; i < n; i++) {
//             if(map[i].empty()) {
//                 result++;
//             }
//             else if(dfs(visited, map, i)){
//                 result++;
//             }
//         }
//         return result;
//     }
// private:
//     bool dfs(vector<bool> &visited, unordered_map<int, vector<int>> &map, int node){
//         if(visited[node] == true) {
//             return false;
//         }
//         visited[node] = true;
//         int n = map[node].size();

//         for(int i = 0; i < n; i++) {
//             dfs(visited, map, map[node][i]);
//         }
//         return true;
//     }
// };