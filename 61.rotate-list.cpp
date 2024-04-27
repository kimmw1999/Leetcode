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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *ptr = new ListNode(0, head);
        ListNode *last = head;
        int n = 1;
        while(last->next != NULL) {
            last = last->next;
            n++;
        }
        k = k % n;

        if(k == 0) {
            return head;
        }
        ListNode *first = head;
        ListNode *second = head;
        for(int i = 0; i < k; i++) {
            second = second->next;
        }

        while(second->next != NULL) {
            second = second->next;
            first = first->next;
        }

        ptr->next = first->next;
        second->next = head;
        first->next = NULL;
        return ptr->next;
    }
};