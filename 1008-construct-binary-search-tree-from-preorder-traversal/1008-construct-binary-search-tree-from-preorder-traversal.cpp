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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < preorder.size(); i++){
            TreeNode *tmp = root;
            while(tmp != NULL){
                if(preorder[i] > tmp->val){
                    if(tmp->right == NULL){
                        tmp->right = new TreeNode(preorder[i]);
                        break;
                    }
                    tmp = tmp->right;
                }else{
                    if(tmp->left == NULL){
                        tmp->left = new TreeNode(preorder[i]);
                        break;
                    }
                    tmp = tmp->left;
                }
            }
        }
        return root;
    }
};