/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        //leetcode solution
        int result = 0;
        dfs(root, result);
        return result;
    }
private:
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        
        result = max(result, left + right);
        return 1 + max(left, right);
    }

    //my solution
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         return maxdiameter(root);
//     }

// private:
//     int maxdiameter(TreeNode* root) {
//         if(root == NULL) {
//             return 0;
//         }
//         int withroot = depth(1, root->left) + depth(1, root->right);
//         int withoutroot = max(maxdiameter(root->left), maxdiameter(root->right));
//         return max(withroot, withoutroot);
//     }
//     int depth(int n, TreeNode* node) {
//         if(node == NULL) {
//             return n-1;
//         }

//         return max(depth(n+1, node->left), depth(n+1, node->right));
//     }
};
// @lc code=end

