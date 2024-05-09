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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = new ListNode(0, head);
        ListNode *sPtr = smaller;
        ListNode *bigger = new ListNode(0, head);
        ListNode *bPtr = bigger;
        // while(head != NULL) {
        //     if(head->val < x) {
        //         sPtr->next = new ListNode(head->val);
        //         sPtr = sPtr->next;
        //     }
        //     else{
        //         bPtr->next = new ListNode(head->val);
        //         bPtr = bPtr->next;
        //     }
        //     head = head->next;
        // }
        // sPtr->next = bigger->next;
        // return smaller->next;

        while(head != NULL) {
            if(head->val < x) {
                bPtr->next = head->next;
                sPtr = head;
            }
            else{
                sPtr->next = head->next;
                bPtr = head;
            }
            head = head->next;
        }
        sPtr->next = bigger->next;
        return smaller->next;
    }
};