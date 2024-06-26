class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n);
        if (hasCycle(adj, visited, -1, 0)) {
            return false;
        }
        
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int parent, int child) {
        if (visited[child]) {
            return true;
        }
        visited[child] = true;
        // checking for cycles and connectedness
        for (int i = 0; i < adj[child].size(); i++) {
            int curr = adj[child][i];
            if (curr != parent && hasCycle(adj, visited, child, curr)) {
                return true;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         vector<vector<bool>> graph(n, vector<bool>(n, false));
//         for(int i = 0; i < edges.size(); i++) {
//             graph[edges[i][0]][edges[i][1]] = true;
//             graph[edges[i][1]][edges[i][0]] = true;
//         }
//         vector<bool> visited(n, false);
//         int count = n;
//         if(!dfs(graph, visited, 0)) {
//             return false;
//         }
//         for(int i = 0 ; i < n; i++) {
//             if(!visited[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// private:
//     bool dfs(vector<vector<bool>> &graph, vector<bool> &visited, int node) {
//         if(visited[node]) {
//             return false;
//         }

//         visited[node] = true;
//         for(int i = 0; i < graph[node].size(); i++) {
//             if(graph[node][i]) {
//                 graph[i][node] = false;
//                 if(!dfs(graph, visited, i)) {
//                     return false;
//                 }
//             }
//         }
//         return true;

//     }
// };