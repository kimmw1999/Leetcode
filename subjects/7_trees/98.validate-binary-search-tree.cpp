/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
#include <limits>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate_tree(root, LONG_MAX, LONG_MIN);
    }

private:
    bool validate_tree(TreeNode *node, long max_num, long min_num) {
        if(node == NULL) {
            return true;
        }
        if(!(node->val < max_num && node->val > min_num)) {
            return false;
        }


        return validate_tree(node->left, node->val, min_num) && validate_tree(node->right, max_num, node->val);
    }
};

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
private:
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) {
            return true;
        }
        
        if (!inorder(root->left, prev)) {
            return false;
        }
        
        if (prev != NULL && prev->val >= root->val) {
            return false;
        }
        prev = root;
        
        if (!inorder(root->right, prev)) {
            return false;
        }
        
        return true;
    }
};
*/

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         stack<TreeNode*> stk;
//         TreeNode* prev = NULL;
        
//         while (!stk.empty() || root != NULL) {
//             while (root != NULL) {
//                 stk.push(root);
//                 root = root->left;
//             }
//             root = stk.top();
//             stk.pop();
            
//             if (prev != NULL && prev->val >= root->val) {
//                 return false;
//             }
            
//             prev = root;
//             root = root->right;
//         }
        
//         return true;
//     }
// };
// @lc code=end

