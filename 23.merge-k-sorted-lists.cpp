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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for(ListNode *node : lists) {
            if(node != NULL) {
                pq.push({-(node->val), node});
            }
        }
        ListNode *h = new ListNode();
        ListNode *ptr = h;
        while(!pq.empty()) {
            pair<int, ListNode*> min_node = pq.top();
            pq.pop();
            ptr->next = min_node.second;
            ptr = ptr->next;
            if(ptr->next != NULL) {
                pq.push({-(ptr->next->val), ptr->next});
            }
        }
        return h->next;
    }
};