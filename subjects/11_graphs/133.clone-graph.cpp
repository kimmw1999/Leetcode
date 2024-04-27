class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// leetcode dfs

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (node == NULL) {
//             return NULL;
//         } 
//         if (m.find(node) == m.end()) {
//             m[node] = new Node(node->val);
//             for (int i = 0; i < node->neighbors.size(); i++) {
//                 Node* neighbor = node->neighbors[i];
//                 m[node]->neighbors.push_back(cloneGraph(neighbor));
//             }
//         }
//         return m[node];
//     }
// private:
//     unordered_map<Node*, Node*> m;
// };

// leetcode bfs

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if (node == NULL) {
//             return NULL;
//         }
        
//         Node* copy = new Node(node->val);
//         m[node] = copy;
        
//         queue<Node*> q;
//         q.push(node);
        
//         while (!q.empty()) {
//             Node* curr = q.front();
//             q.pop();
            
//             for (int i = 0; i < curr->neighbors.size(); i++) {
//                 Node* neighbor = curr->neighbors[i];
                
//                 if (m.find(neighbor) == m.end()) {
//                     m[neighbor] = new Node(neighbor->val);
//                     q.push(neighbor);
//                 }
                
//                 m[curr]->neighbors.push_back(m[neighbor]);
//             }
//         }
        
//         return copy;
//     }
// private:
//     unordered_map<Node*, Node*> m;
// };


// my solution
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(node == NULL) {
//             return NULL;
//         }
//         if(node->neighbors.size() == 0) {
//             return new Node(node->val);
//         }
//         cloneNode(node);
//         return cloned_nodes[node->val];
//     }
// private:
//     unordered_map<int, Node*> cloned_nodes;
//     void cloneNode(Node *node) {
//         if(cloned_nodes.find(node->val) != cloned_nodes.end()) {
//             return;
//         }
//         Node *new_node = new Node(node->val);
//         vector<Node*> neighbors;
//         cloned_nodes[node->val] = new_node;
//         for(Node *orig_nb : node->neighbors) {
//             cloneNode(orig_nb);
//             neighbors.push_back(cloned_nodes[orig_nb->val]);
//         }
//         new_node->neighbors = neighbors;
//         return;
//     }
// };
// @lc code=end

