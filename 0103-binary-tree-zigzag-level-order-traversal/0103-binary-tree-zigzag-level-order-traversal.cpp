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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> out;
        queue<TreeNode*> q;
        int level = 0;
        
        if(root == NULL)
            return ans;
        
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 1){
            TreeNode *node = q.front();
            q.pop();
            
            if(node == NULL){
                if(level%2 != 0){
                    reverse(out.begin(), out.end());
                }
                ans.push_back(out);
                level++;
                q.push(NULL);
                out.resize(0);
            }else{
                out.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
        }
        if(level%2 != 0)
            reverse(out.begin(), out.end());
        ans.push_back(out);
        return ans;
    }
   
};