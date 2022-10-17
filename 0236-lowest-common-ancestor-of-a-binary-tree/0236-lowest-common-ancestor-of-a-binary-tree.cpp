/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findThePath(TreeNode *root, vector<TreeNode*> &path, vector<TreeNode*> &out, TreeNode *target){
        if(root == NULL)
            return;
        out.push_back(root);
        if(root->val == target->val){
            path = out;
            return;
        }
        findThePath(root->left, path, out, target);
        findThePath(root->right, path, out, target);
        out.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        vector<TreeNode*> out;
        TreeNode *lcs = NULL;
        
        findThePath(root, p_path, out, p);
        out.resize(0);
        findThePath(root, q_path, out, q);
        
        for(int i = 0; (i < p_path.size() && i < q_path.size()); i++){
            if(p_path[i]->val != q_path[i]->val)
                break;
            lcs = p_path[i];
        }
        return lcs;
    }
};