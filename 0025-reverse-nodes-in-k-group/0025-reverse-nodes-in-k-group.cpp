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
    ListNode* reverse(ListNode *tmp){
        ListNode *curr = tmp, *prev = NULL, *next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *getkthNode(ListNode *tmp, int k){
        k--;
        while(tmp != NULL && k > 0){
            k--;
            tmp = tmp->next;
        }
        return tmp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmp=head, *prev=NULL;
        
        while(tmp != NULL){
            ListNode *kthnode = getkthNode(tmp,k);
            if(kthnode == NULL){
                if(prev != NULL)
                    prev->next = tmp;
                break;
            }
            ListNode *next = kthnode->next;
            kthnode->next = NULL;
            reverse(tmp);
            if(tmp == head){
                head=kthnode;
            }else{
                prev->next = kthnode;    
            }
            prev = tmp;
            tmp = next;
        }
        return head;
    }
};