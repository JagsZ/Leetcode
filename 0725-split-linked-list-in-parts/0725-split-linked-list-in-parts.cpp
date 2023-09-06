/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, NULL);
        int n = 0, len = 0, rem = 0;
        ListNode *tmp = head, *tmp1 = head;
        
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }
        tmp = head;
        
        len = n/k;
        rem = n % k;
        for(int i = 0; i < k && tmp; i++){
           
            ans[i] = tmp;
            for(int j = 1; j <= (len+(rem>0?1:0)); j++ ){
                tmp1 = tmp;
                tmp = tmp->next;
            }
            tmp1->next = NULL;
            len = n/k;
            rem--;
        }
        return ans;
        
    }
};