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
    int findLeft(TreeNode *root){
        int h = 0;
        while(root != NULL){
            h++;
            root = root->left;
        }
        return h;
    }
    int findRight(TreeNode *root){
        int h = 0;
        while(root != NULL){
            h++;
            root = root->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        
        int lh = findLeft(root);
        int rh = findRight(root);
        if(lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};