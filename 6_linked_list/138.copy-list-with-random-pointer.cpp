/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* h = head;
        
        while (h){
            nodes[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while (h){
            Node* newNode = nodes[h];
            newNode->next = nodes[h->next];
            newNode->random = nodes[h->random];
            h = h->next;
        }
        return nodes[head];
        // unordered_map<int, pair<Node*, int>> map
        // unordered_map<int, Node*> original_map;
        // Node *ptr = head;
        // int i = 0;

        // if(head == NULL) {
        //     return NULL;
        // }
        // if(head->next == NULL) {
        //     if(head->random == NULL) {
        //         return new Node(head->val);
        //     }
        //     else{
        //         Node *copy_node = new Node(head->val);
        //         copy_node->random = copy_node;
        //         return copy_node;
        //     }
        // }
        // while(ptr != NULL) {
        //     original_map[i] = ptr;

        //     map[i] = pair(new Node(ptr->val), -1);
        //     if(i > 0){
        //         map[i-1].first->next = map[i].first;
        //     }

        //     ptr = ptr->next;
        //     i++;
        // }
        // int lst_size = i;
        // cout<<lst_size;
        // i = 0;
        // ptr = head;
        // int count = 0;
        // while(i < lst_size) {
        //     //count random idx
        //     count = 0;
        //     cout << i;
        //     Node *random_node = original_map[i]->random;
        //     while(random_node != NULL){
        //         random_node = random_node->next;
        //         count++;
        //     }
        //     map[i] = pair(map[i].first, lst_size - count);
        //     i++;
        // }

        // i = 0;
        // Node *curr;
        // int random_idx;
        // while(i < lst_size){
        //     cout <<endl;
        //     curr = map[i].first;
        //     random_idx = map[i].second;
        //     cout << map[i].first->val << " " << map[i].second;
        //     if(random_idx != lst_size) {
        //         curr->random = map[random_idx].first;
        //     }
        //     i++;
        // }
        // cout << "finished";
        // return map[0].first;
    }
};
// @lc code=end

