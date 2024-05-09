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
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode *>> memo;
        return getSubTree(1, n, memo);
    }

    vector<TreeNode *> getSubTree(int start, int end, map<pair<int, int>, vector<TreeNode *>> &memo) {
        vector<TreeNode *> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }

        if(memo.find({start, end}) != memo.end()) {
            return memo[{start, end}];
        }

        for(int i = start; i <= end; i++) {
            vector<TreeNode *> left = getSubTree(start, i-1, memo);
            vector<TreeNode *> right = getSubTree(i+1, end, memo);

            for(TreeNode *l : left) {
                for(TreeNode *r : right) {
                    TreeNode *head = new TreeNode(i, l, r);
                    res.push_back(head);
                }
            }
        }

        return res;
    }
};