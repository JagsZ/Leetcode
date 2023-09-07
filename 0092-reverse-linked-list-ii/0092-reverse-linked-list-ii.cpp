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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        
        if(curr == NULL)
            return curr;
        
        while(left > 1){
            prev = curr;
            curr = curr->next;
            left--;
            right--; 
        }
        ListNode *con = prev, *tail = curr;
        ListNode *third = NULL;
        while(right > 0)
        {
            third =  curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
            right--;
        }
        if(con != NULL){
            con->next = prev;
        }else{
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};