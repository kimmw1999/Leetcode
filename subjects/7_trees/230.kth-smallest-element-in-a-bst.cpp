/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    //leetcode solution
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }
private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int idx = 1;
//         int result = -1;
//         bool found = false;
//         inOrder(root, idx, result, k, found);
//         return result;
//     }
// private:
//     void inOrder(TreeNode *node, int &curridx, int &result, int &k, bool &found) {
//         if(node == NULL) {
//             return;
//         }
//         if(node->left == NULL && node -> right == NULL) {
//             if(curridx == k && !found) {
//                 result = node->val;
//                 found = true;
//                 return;
//             }
//             curridx++;
//             return;
//         }

//         inOrder(node->left, curridx, result, k, found);
//         if(curridx == k && !found) {
//             found = true;
//             result = node->val;
//             return;
//         }
//         curridx++;
//         inOrder(node->right, curridx, result, k, found);
//     }
// };
// @lc code=end

