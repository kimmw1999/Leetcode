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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *ptr = new ListNode(0, head);
        ListNode *prev = ptr;
        ListNode *curr = prev->next;

        while(prev->next != NULL) {
            if(curr == NULL || curr->next == NULL) {
                prev->next = curr;
                break;
            }

            if(curr->val != curr->next->val) {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }

            else{
                prev->next = curr;
                prev = curr;
                int curVal = curr->val;
                while(curr != NULL && curr->val == curVal) {
                    curr = curr->next;
                }
            }
        }
        return ptr->next;
    }
};