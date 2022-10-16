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
   bool isMirror(TreeNode *l, TreeNode *r){
       if(l == NULL && r == NULL)
           return true;
       if(l == NULL || r == NULL)
           return false;
       if(l->val != r->val)
           return false;
       if(isMirror(l->left, r->right) == false)
           return false;
       if(isMirror(r->right, l->left) == false)
           return false;
       return true;
   }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};