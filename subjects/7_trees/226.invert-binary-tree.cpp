/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

        
        //my solution
//         if(root == NULL) {
//             return NULL;
//         }
//         return invert(root);
//     }

// private:
//     TreeNode* invert(TreeNode* Node) {
//         if(Node->left == NULL && Node->right == NULL) {
//             return Node;
//         }

//         if(Node->left == NULL) {
//             Node->left = invert(Node->right);
//             Node->right = NULL;
//         }
//         else if(Node->right == NULL) {
//             Node->right = invert(Node->left);
//             Node->left = NULL;
//         }
//         else{
//             TreeNode *temp = Node->left;
//             Node->left = invert(Node->right);
//             Node->right = invert(temp);
//         }
//         return Node;
    }
};
// @lc code=end

