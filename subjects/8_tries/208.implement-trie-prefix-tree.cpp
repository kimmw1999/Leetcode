/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <string>
using namespace std;
struct Node{
    bool isEnd = false;
    Node *children[26]; //will contain a~z. placeholder initially
    Node(){
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *ptr = root;
        for(char ch:word) {
            if(ptr->children[ch - 'a'] == NULL) {
                ptr->children[ch-'a'] = new Node();
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isEnd = true;
    }
    
    bool search(string word) {
        Node *ptr = root;
        for(char ch:word) {
            if(ptr->children[ch - 'a'] == NULL) {
                return false;
            }
            else{
                ptr = ptr->children[ch-'a'];
            }
        }
        return ptr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *ptr = root;
        for(char ch:prefix) {
            if(ptr->children[ch - 'a'] == NULL) {
                return false;
            }
            else{
                ptr = ptr->children[ch-'a'];
            }
        }
        return true;
    }
private:
    Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

