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
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *front = head;
        for(int i = 0; i < left-2; i++) {
            front = front->next;
        }
        ListNode *prev = front; // save previous node which is out of reversed range
        front = front->next;

        if(left == 1) {
            prev = new ListNode(0, head);
            front = head;
        }
        ListNode *curr = front->next;
        ListNode *tail = front;

        for(int i = 0; i < right - left; i++) {
            front->next = curr->next;
            curr->next = tail;
            tail = curr;
            curr = front->next;
        }

        prev->next = tail;

        return (left == 1) ? tail : head;
    }
};