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
int mod = 1e9+7;
class Solution {
    int sumOfTree(TreeNode *root){
        if(root == NULL)
            return 0;
        
        int left = sumOfTree(root->left);
        int right = sumOfTree(root->right);
        return (root->val + (left+right));
    }
    
    int solve(TreeNode *root, int &total_sum, long long &product){
        if(root == NULL)
            return 0;
        
        int left = solve(root->left, total_sum, product);
        int right = solve(root->right, total_sum, product);
        int sum = left + right + root->val;
        long long total_product = (long)sum * (total_sum - sum);
        product = max(product, total_product);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        int total_sum = 0;
        long long product = 0;
        total_sum = sumOfTree(root);
        solve(root, total_sum, product);
        return product % mod;
    }
};