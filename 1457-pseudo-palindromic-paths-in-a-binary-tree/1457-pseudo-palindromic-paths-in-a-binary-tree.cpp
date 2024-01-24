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
    int dfs(TreeNode *root, int bit_mask){
        if(root == NULL)
            return 0;
        
        bit_mask ^= (1 << root->val);
        if(root->left == NULL && root->right == NULL)
            return ((bit_mask == 1) || (bit_mask & (bit_mask-1)) == 0);
        
        int left = dfs(root->left, bit_mask);
        int right = dfs(root->right, bit_mask);
        return (left+right);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int bit_mask = 0;
        return dfs(root, bit_mask);
    }
};