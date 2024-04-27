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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *result = new ListNode();
        ListNode *ptr = result;
        while(l1 != NULL || l2 != NULL) {
            ptr->next = addNodes(l1, l2, c);
            ptr = ptr->next;
            if(l1 != NULL) {
                l1 = l1->next;
            }
            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        if(c == 1) {
            ptr->next = new ListNode(1);
        }
        return result->next;
    }
private:
    ListNode *addNodes(ListNode *l1, ListNode *l2, int &c) {
        if(l1 == NULL) {
            if(l2->val == 9 && c == 1) {
                return new ListNode(0);
            }
            else{
                int sum = l2->val + c;
                c = 0;
                return new ListNode(sum);
            }
        }
        else if(l2 == NULL) {
            if(l1->val == 9 && c == 1) {
                return new ListNode(0);
            }
            else {
                int sum = l1->val + c;
                c = 0;
                return new ListNode(sum);
            }
        }

        else{
            int sum = l1->val + l2->val + c;
            c = sum / 10;
            sum = sum % 10;
            return new ListNode(sum);
        }
    }
};