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
    int maxPath(TreeNode *root, int &ans){
        if(root == NULL)
            return 0;
        int left = maxPath(root->left, ans);
        int right = maxPath(root->right, ans);
        int sum = max(root->val, max(root->val+left, root->val+right));
        int max_sum = max(sum, (root->val + left + right));
        ans = max(ans, max_sum);
        return sum;
    }
    /*void solve(TreeNode *root, int &ans){
        if(root == NULL)
            return;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        int sum = root->val + left + right;
        ans = max(ans, max(sum, max(root->val, max(root->val+left, root->val+right))));
        solve(root->left, ans);
        solve(root->right, ans);
    }*/
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};