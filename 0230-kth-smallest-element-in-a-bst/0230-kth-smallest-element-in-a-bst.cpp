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
    void helper(TreeNode *root,vector<int> &out){
        
        if(root == NULL){
            return;
        }
        helper(root->left, out);
        out.push_back(root->val);
        helper(root->right, out);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> out;
        helper(root,out);
        return out[k-1];
    }
};