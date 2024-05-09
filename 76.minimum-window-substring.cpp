/*
Date: 04/28/2024
Complexity:
  time - O(|S| + |T|)
  space - O(|S| + |T|)
*/
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
      //get t map
      unordered_map<char, int> tMap;
      for(char ch : t) {
        tMap[ch]++;
      }
      int tSize = tMap.size();

      //filter s
      struct element {
        char ch;
        int i;

        element(char ch, int i) : ch(ch), i(i) {}
      };
      vector<element> sFiltered;
      for(int i = 0; i < s.size(); i++) {
        if(tMap.find(s[i]) != tMap.end()) {
          element e = element(s[i], i);
          sFiltered.push_back(e);
        }
      }

      //setup pointers
      int l = 0;
      int r = 0;
      int ans[3] = {-1, 0, 0}; //initial len = -1, return ""
      unordered_map<char, int> sMap;
      int sSize = 0;

      while(r < sFiltered.size()) {
        char ch = sFiltered[r].ch;

        //s[r] added
        sMap[ch]++;

        //after added, if added one fits the t requirement
        if(sMap[ch] == tMap[ch]) {
          sSize++;
        }
        
        //if valid, shrink from left until invalid
        while(l <= r && sSize == tSize) {
          //it's valid, so check if minimum
          char ch = sFiltered[l].ch;
          int start = sFiltered[l].i;
          int end = sFiltered[r].i;
          if(ans[0] == -1 || ans[2] - ans[1] + 1 > end - start + 1) {
            ans[0] = end - start + 1;
            ans[1] = start;
            ans[2] = end;
          }

          //shrink from left
          sMap[ch]--;
          if(sMap[ch] < tMap[ch]) {
            sSize--;
          }

          l++;
        }

        r++;
      }
      return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};