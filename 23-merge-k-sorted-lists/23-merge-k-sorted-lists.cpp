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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-101);
        ListNode *tmp = dummy;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tmp->next = list1;
                list1 = list1->next;
            }
            else{
                tmp->next = list2;
                list2 =list2->next;
            }
            tmp = tmp->next;
        }
        while( list1 != NULL){
            tmp->next = list1;
            list1 = list1->next; 
            tmp = tmp->next;
        }
        while(list2 != NULL){
            tmp->next = list2;
            list2 = list2->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        for(auto x : lists){
            head = mergeTwoLists(head, x);
        }
        return head;
    }
};