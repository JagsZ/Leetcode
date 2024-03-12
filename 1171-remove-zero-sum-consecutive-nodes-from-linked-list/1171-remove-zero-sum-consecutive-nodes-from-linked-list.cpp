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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        unordered_map<int, ListNode*> um;

        int prefixSum = 0;
        while (temp != NULL) {
            prefixSum += temp->val;
            um[prefixSum] = temp;
            temp = temp->next;
        }

        prefixSum = 0;
        temp = dummy;
        while (temp != NULL) {
            prefixSum += temp->val;
            temp->next = um[prefixSum]->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};