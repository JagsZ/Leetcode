/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != NULL && head->next != NULL){
            if(set.find(head->next) != set.end()){
                return head->next;
            }
            set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};