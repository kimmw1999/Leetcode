/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <memory>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int count = q.size();
            vector<int> curr;
            
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                curr.push_back(node->val);
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            
            result.push_back(curr);
        }
        
        return result;
    }
};
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         traverse(1, root);
//         return output;
//     }
// private:
//     vector<vector<int>> output;
//     int output_size = 0;
//     void traverse(int level, TreeNode *node) {
//         if(node == NULL) {
//             return;
//         }
//         if(output_size < level) {
//             output.push_back({node->val});
//             output_size++;
//         }
//         else{
//             output[level-1].push_back(node->val);
//         }
//         traverse(level+1, node->left);
//         traverse(level+1, node->right);
//     }
// };
// @lc code=end

