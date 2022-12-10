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
    int solve(TreeNode *root, int max_val, int min_val){
        if(root == NULL)
            return INT_MIN;
        int res = max(abs(max_val - root->val), abs(min_val - root->val));
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        int left_res =  max(res, solve(root->left, max_val, min_val));
        int right_res = max(res, solve(root->right, max_val, min_val));
        return max(left_res, right_res);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return max(solve(root->left, root->val, root->val), solve(root->right, root->val, root->val));
    }
};