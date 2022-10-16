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
    void treeLeftSide(TreeNode *root, vector<int> &ans){
        if(root == NULL)
            return;
        if(root->left != NULL || root->right != NULL)
            ans.push_back(root->val);
        
        treeLeftSide(root->left, ans);
        if(root->left == NULL)
            treeLeftSide(root->right, ans);
    }
    
    void treeRightSide(TreeNode *root, vector<int> &ans){
        if(root == NULL)
            return;
        
        treeRightSide(root->right, ans);
        if(root->right == NULL)
            treeRightSide(root->left, ans);
        if(root->left != NULL || root->right != NULL)
            ans.push_back(root->val);
    }
    
    void treeLeafNode(TreeNode *root, vector<int> &ans){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return;
        }
        
        treeLeafNode(root->left, ans);
        treeLeafNode(root->right, ans);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;    
        ans.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
            return ans;
       
        // Left side
        treeLeftSide(root->left, ans);
        
        // leaf nodes
        treeLeafNode(root, ans);
        
        // right side;
        treeRightSide(root->right, ans);
        return ans;
    }
};