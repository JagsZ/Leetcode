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
    TreeNode *node1 = NULL, *node2 = NULL, *prev = NULL;
    void solve(TreeNode *root){
        if(root == NULL)
            return;
        
        solve(root->left);    
        if(prev != NULL && root->val < prev->val){    
            node2 = root;
            if(node1 == NULL)
                node1 = prev;
            else
                return;
        }
        prev  = root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL;
        solve(root);
        swap(node1->val, node2->val);
    }
};