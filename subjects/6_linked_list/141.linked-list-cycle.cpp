/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //O(1) memory solution
        if(head == NULL) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;

        // O(N) memory solution
        // unordered_set<ListNode*> node_set;
        // ListNode *head_ptr = head;
        // while(head_ptr != NULL) {
        //     node_set.insert(head_ptr);
        //     if(node_set.find(head_ptr->next) != node_set.end()) {
        //         return true;
        //     }
        //     head_ptr = head_ptr->next;
        // }
        // return false;

    }
};
// @lc code=end

