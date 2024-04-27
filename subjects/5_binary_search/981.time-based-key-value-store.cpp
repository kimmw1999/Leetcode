/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class TimeMap {
    //leetcode solution
// public:
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         m[key].push_back({timestamp, value});
//     }
    
//     string get(string key, int timestamp) {
//         if (m.find(key) == m.end()) {
//             return "";
//         }
        
//         int low = 0;
//         int high = m[key].size() - 1;
        
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (m[key][mid].first < timestamp) {
//                 low = mid + 1;
//             } else if (m[key][mid].first > timestamp) {
//                 high = mid - 1;
//             } else {
//                 return m[key][mid].second;
//             }
//         }
        
//         if (high >= 0) {
//             return m[key][high].second;
//         }
//         return "";
//     }
// private:
//     unordered_map<string, vector<pair<int, string>>> m;
// };

//my solution
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back(pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(map.find(key) == map.end()) {
            return "";
        }
        
        int i = 0;
        int j = map[key].size() - 1;
        int m;
        
        while ( i <= j ) {
            m = (i + j) / 2;
            if(map[key][m].first < timestamp) {
                i = m + 1;
            }

            else if(map[key][m].first == timestamp){
                return map[key][m].second;
            }

            else{
                j = m - 1;
            }
        }
        if(j >= 0) {
            return map[key][j].second;
        }
        return "";

    }

private:
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

