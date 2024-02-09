/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* dummy = new ListNode();
        ListNode *curr = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if (list1 == NULL) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        
        return dummy->next;

        // ListNode *headptr = new ListNode();
        // ListNode *newhead = new ListNode();
        // headptr->next = newhead;
        // ListNode *head1 = list1;
        // ListNode *head2 = list2;
        // while(head1 != NULL || head2 != NULL) {
        //     if(head1 == NULL) {
        //         newhead->next = new ListNode(head2->val);
        //         head2 = head2->next;
        //     }
        //     else if(head2 == NULL) {
        //         newhead->next = new ListNode(head1->val);
        //         head1 = head1->next;
        //     }
        //     else{
        //         if(head1->val <= head2->val) {
        //             newhead->next = new ListNode(head1->val);
        //             head1 = head1->next;
        //         }
        //         else{
        //             newhead->next = new ListNode(head2->val);
        //             head2 = head2->next;
        //         }
        //     }
        //     newhead = newhead->next;
        // }
        // return headptr->next->next;
    }
};
// @lc code=end

