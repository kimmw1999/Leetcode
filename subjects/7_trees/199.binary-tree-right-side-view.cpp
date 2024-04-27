/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> curr;
            int count = q.size();
            for(int i = 0; i < count; i++) {
                TreeNode *node = q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            result.push_back(curr.back());
        }
        return result;
    }
};
// @lc code=end

