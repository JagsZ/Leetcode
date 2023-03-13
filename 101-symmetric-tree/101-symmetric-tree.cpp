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
    bool solve(TreeNode *root1, TreeNode *root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return NULL;
        
        if(root1->val != root2->val)
            return false;
        
        bool left = solve(root1->left, root2->right);
        bool right = solve(root1->right, root2->left);
        return (left && right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};