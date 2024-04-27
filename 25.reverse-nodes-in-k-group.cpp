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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        if(k == 1) {
            return head;
        }
        ListNode *h = new ListNode(0, head);
        ListNode *prev = h;
        ListNode *next = h;
        for(int i = 0; i < k; i++) {
            next = next->next;
        }
        next = next->next;

        swap(prev, next, k);
        while(true) {
            for(int i = 0; i < k; i++) {
                if(next == NULL) {
                    return h->next;
                }
                if(i != k-1 && !next->next) {
                    return h->next;
                }
                next = next->next;
                prev = prev->next;
            }
            swap(prev, next, k);
        }
        return h->next;
    }

private:
    void swap(ListNode *prev, ListNode *next, int k) {
        ListNode *h = prev;
        ListNode *first = prev->next;
        ListNode *second = first;
        ListNode *third = second->next;
        ListNode *fourth = third->next;

        for(int i = 0; i < k-1; i++) {
            second->next = fourth;
            third->next = first;
            h->next = third;
            
            first = third;
            third = fourth;
            if(fourth == NULL){
                return;
            }
            fourth = fourth->next;
        }

    }
};