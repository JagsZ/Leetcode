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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        flatten(root->left);
        
        if(root->left != NULL){
            if(root->right != NULL){
                TreeNode *tmp = root->right;
                root->right = root->left;
                TreeNode *left = root->left;
                root->left = NULL;
                while(left != NULL && left->right != NULL)
                    left = left->right;
                left->right = tmp;
            }else{
                root->right = root->left;
                root->left = NULL;
            }
        }
        flatten(root->right);
    }
};