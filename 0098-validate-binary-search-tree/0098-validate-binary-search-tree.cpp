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
    bool isValidBST(TreeNode* root) {
        
    TreeNode *node =  NULL;
    long long max_val = LLONG_MIN;
    stack<TreeNode *> st;

    while((st.empty() ==  false) || root != NULL){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        node = st.top();
        st.pop();
        if(max_val >= node->val)
            return false;
        max_val = node->val;
        root = node->right;
    }
    return true;
    }
};