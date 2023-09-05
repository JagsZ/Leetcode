/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {/*
    void printList(Node *head){
        while(head != NULL){
            cout<<head->val <<" ";
            if(head->random != NULL){
                //cout<<"random" << head->random->val << " "; 
            }
            head=head->next;
        }
        cout<<endl;
    }*/
public:
    Node* copyRandomList(Node* head) {
        Node *tmp=head, *clone=NULL,*chead=NULL;
        if(head == NULL){
            return NULL;
        }
        while(tmp != NULL){
            int val = tmp->val;
            Node *node = new Node(val);
            node->val = val;
            node->next = NULL;
            node->random = NULL;
            node->next = tmp->next;
            tmp->next = node;
            tmp=node->next;
        }
        //printList(head);
        tmp = head;
        clone = tmp->next;
        chead=clone;
        while(tmp != NULL){
            clone = tmp->next;
            if(tmp->random != NULL)
                clone->random = tmp->random->next;
            tmp = clone->next;
        }
        //printList(head);
        tmp = head;
        clone = tmp->next;
        while(clone != NULL){
            tmp->next = clone->next;
            tmp = tmp->next;
            clone->next = (tmp != NULL)?tmp->next: NULL;
            clone=clone->next;
        }
        //printList(head);
        //printList(chead);
        return chead;
    }
};