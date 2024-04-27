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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = new ListNode(0, head);
        ListNode *h = prev;
        ListNode *next = prev;
        for(int i = 0; i < n; i++) {
            next = next->next;
        }
        while(next->next != NULL) {
            prev = prev->next;
            next = next->next;
        }
        prev->next = prev->next->next;
        return h->next;
    }
};