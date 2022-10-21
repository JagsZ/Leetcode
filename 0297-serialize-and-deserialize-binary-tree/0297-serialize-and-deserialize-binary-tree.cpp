/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        if(root == NULL)
            return ans;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node == NULL)
                ans += "#,";
            else
                ans += to_string(node->val) + ",";
            
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);   
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        stringstream s(data);
        string str = "";
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#")
                node->left = NULL;
            else{
                TreeNode * left_child = new TreeNode(stoi(str));
                node->left = left_child;
                q.push(left_child);
            }
            getline(s, str, ',');
            if(str == "#")
                node->right = NULL;
            else{
                TreeNode * right_child = new TreeNode(stoi(str));
                node->right = right_child;
                q.push(right_child);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));