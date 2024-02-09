/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *sum_ptr = dummy;
        ListNode *l1_ptr = l1;
        ListNode *l2_ptr = l2;
        int carry = 0;
        int sum = 0;
        int l1_val;
        int l2_val;
        while(l1_ptr != NULL || l2_ptr != NULL) {
            if(l1_ptr == NULL) {
                l1_val = 0;
            }
            else{
                l1_val = l1_ptr->val;
                l1_ptr = l1_ptr->next;
            }
            if(l2_ptr == NULL) {
                l2_val = 0;
            }
            else{
                l2_val = l2_ptr->val;
                l2_ptr = l2_ptr->next;
            }

            sum = l1_val + l2_val + carry;
            if (sum >= 10){
                sum -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }

            sum_ptr->next = new ListNode(sum);
            sum_ptr = sum_ptr->next;
            
            
        }
        if(carry == 1) {
            sum_ptr->next = new ListNode(1);
        }
        return dummy->next;
    }
};
// @lc code=end

