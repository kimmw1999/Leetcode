/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class TrieNode{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ptr = root;
        for(char ch:word) {
            if(ptr->children[ch-'a'] == NULL) {
                ptr->children[ch-'a'] = new TrieNode();
            }
            ptr = ptr->children[ch-'a'];
        }
        ptr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *ptr = root;
        return trie_search(word, 0, ptr);
    }

private:
    TrieNode *root;

    bool trie_search(string word, int i, TrieNode *node) {
        if(node == NULL) {
            return false;
        }
        if(i == word.size()) {
            return node->isWord;
        }
        if(word[i] != '.') {
            return trie_search(word, i+1, node->children[word[i] - 'a']);
        }
        for(int j = 0; j < 26; j++) {
            if(trie_search(word, i+1, node->children[j])) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

