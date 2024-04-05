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
     ListNode *head1 = NULL;
     void reverse(ListNode *head,ListNode *prev){
         if(head == NULL)
             return;
         if(head->next == NULL){
             head1 = head;
             head->next = prev;
             return;
         }
         reverse(head->next,head);
         head->next = prev;
     }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode *prev = NULL;
       reverse(head, prev);
       return head1;
    }
};