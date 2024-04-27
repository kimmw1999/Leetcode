/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
//         SearchTree(root, p, p_ancestors);
//         SearchTree(root, q, q_ancestors);
        
//         int i = 0;
//         int n1 = p_ancestors.size();
//         int n2 = q_ancestors.size();
//         int j = 0;
//         while(i < n1 && j < n2) {
//             if(p_ancestors[i] != q_ancestors[i]) {
//                 return p_ancestors[i-1];
//             }
//             i++;
//             j++;
//         }
//         return p_ancestors[i-1];
//     }

// private:
//     vector<TreeNode*> p_ancestors;
//     vector<TreeNode*> q_ancestors;

//     void SearchTree(TreeNode *root, TreeNode* p, vector<TreeNode*> &lst) {
//         lst.push_back(root);
//         if(root-> val == p-> val) {
//             return;
//         }
//         else if(root->val < p->val) {
//             SearchTree(root->right, p, lst);
//         }
//         else{
//             SearchTree(root->left, p, lst);
//         }
//     }
};
// @lc code=end



