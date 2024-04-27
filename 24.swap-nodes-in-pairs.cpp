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
    ListNode* swapPairs(ListNode* head) {
        ListNode *h = new ListNode(0, head);
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return head;
        }
        if(head->next->next == NULL) {
            h->next = head->next;
            head->next = NULL;
            h->next->next = head;
            return h->next;
        }
        ListNode *ptr = h;
        ListNode *prev = ptr->next;
        ListNode *curr = prev->next;
        ListNode *next = curr->next;

        //swap
        while(true) {
            prev->next = next;
            curr->next = prev;
            ptr->next = curr;
            //move ptr, prev, curr, next twice
            if(next == NULL || next->next == NULL) {
                return h->next;
            }
            next = next->next->next;
            curr = curr->next->next->next;
            prev = prev->next;
            ptr = ptr->next->next;
        }
        return h->next;

    }
};