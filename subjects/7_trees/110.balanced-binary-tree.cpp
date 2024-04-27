/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <cmath>
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int left_len = getDepth(1, root->left);
        int right_len = getDepth(1, root->right);
        return (left_len > -1 && right_len > -1 && abs(left_len - right_len) <= 1);
    }
private:
    int getDepth(int n, TreeNode* root) {
        if(root == NULL) {
            return n-1;
        }
        int left_len = getDepth(n+1, root->left);
        int right_len = getDepth(n+1, root->right);
        if(left_len == -1 || right_len == -1) {
            return -1;
        }
        if(abs(left_len - right_len) <= 1) {
            return max(left_len, right_len);
        }
        else{
            return -1;
        }
    }

// leetcode solution
// public:
//     bool isBalanced(TreeNode* root) {
//         int height = 0;
//         return dfs(root, height);
//     }
// private:
//     bool dfs(TreeNode* root, int& height) {
//         if (root == NULL) {
//             height = -1;
//             return true;
//         }
        
//         int left = 0;
//         int right = 0;
        
//         if (!dfs(root->left, left) || !dfs(root->right, right)) {
//             return false;
//         }
//         if (abs(left - right) > 1) {
//             return false;
//         }
        
//         height = 1 + max(left, right);
//         return true;
//     }
};
// @lc code=end

