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
    int findBottomLeftValue(TreeNode* root) 
    {
       int ans=0;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           int flag=0;
           while(n)
           {
               TreeNode* node=q.front();
               q.pop();
               if(flag==0)
               {
                   ans=node->val;
                   flag=1;
               }
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);
               n--;
           }
       }
       return ans;
    }
};