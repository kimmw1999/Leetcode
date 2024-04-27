/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_idx = 0;
        int i = 0;
        int j = inorder.size()-1;
        return build_tree(preorder, inorder, root_idx, i, j);
    }

private:
    TreeNode* build_tree(vector<int> &preorder, vector<int> &inorder, int &root_idx, int i, int j) {
        if(i > j) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[root_idx]);
        int split;
        for(int k = 0; k < inorder.size(); k++) {
            if(preorder[root_idx] == inorder[k]) {
                split = k;
            }
        }

        root_idx++;

        root->left = build_tree(preorder, inorder, root_idx, i, split-1);
        root->right = build_tree(preorder, inorder, root_idx, split+1, j);
        return root;
    }


};
// @lc code=end

