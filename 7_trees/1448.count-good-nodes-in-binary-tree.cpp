/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
#include <iostream>
class Solution {
public:
    int goodNodes(TreeNode* root) {
        countNodes(root, root->val);
        return count;
    }
private:
    int count = 0;
    void countNodes(TreeNode* root, int max_num) {
        if(root == NULL) {
            return;
        }
        int next_max = max_num;
        if(root->val >= max_num) {
            cout << root->val << " " << max_num << endl;
            count++;
            next_max = root->val;
        }
        
        countNodes(root->left, next_max);
        countNodes(root->right, next_max);
    }
};

// public:
//     int goodNodes(TreeNode* root) {
//         int result = 0;
//         dfs(root, root->val, result);
//         return result;
//     }
// private:
//     void dfs(TreeNode* root, int maxSoFar, int& result) {
//         if (root == NULL) {
//             return;
//         }
        
//         if (root->val >= maxSoFar) {
//             result++;
//         }
        
//         dfs(root->left, max(maxSoFar, root->val), result);
//         dfs(root->right, max(maxSoFar, root->val), result);
//     }
// };
// @lc code=end

