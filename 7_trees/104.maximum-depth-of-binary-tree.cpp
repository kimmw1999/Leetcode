/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return getDepth(1, root);
    }

private:
    int getDepth(int n, TreeNode *node){
        if(node->left == NULL && node->right == NULL) {
            return n;
        }
        int l_depth = n;
        int r_depth = n;
        if(node->left != NULL) {
            l_depth = getDepth(n+1, node->left);
        }
        if(node->right != NULL) {
            r_depth = getDepth(n+1, node->right);
        }
        return max(l_depth, r_depth);
    }
};
// @lc code=end

