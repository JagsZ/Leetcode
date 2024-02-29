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
    bool check_order(vector<int> &nums, int odd_even){
        if(nums.size() == 0)
            return true;
        if(odd_even){
            if(nums[0]%2 != 0)
                return false;
            for(int i = 1; i < nums.size(); i++){
                if((nums[i] >= nums[i-1]) || (nums[i])%2 != 0)
                    return false;
            }
        }else{          
            if(nums[0]%2 == 0)
                return false;
            for(int i = 1; i < nums.size(); i++){
                if((nums[i] <= nums[i-1]) || (nums[i])%2 == 0)
                    return false;
            }
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        vector<int> val;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 1){
            TreeNode *node = q.front();
            q.pop();
    
            if(node == NULL){
                if(check_order(val, level%2) == false)
                    return false;
                q.push(NULL);
                val.resize(0);
                level++;
            }else{
                val.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
        }
        if(check_order(val, level%2) == false)
            return false;
        return true;
    }
};