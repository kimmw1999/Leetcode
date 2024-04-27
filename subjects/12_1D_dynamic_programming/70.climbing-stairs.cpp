/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        //dp & memoization
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }
        int first = 1;
        int second = 2;
        int result = 0;
        for(int i = 2; i < n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> db(n+1, 1);
//         vector<bool> visited(n+1, false);
//         visited[0] = true;
//         visited[1] = true;
//         return climb(db, visited, n);
//     }
// private:
//     int climb(vector<int> &db, vector<bool> &visited, int n){
//         if(visited[n]) {
//             return db[n];
//         }
//         int result = climb(db, visited, n-1) + climb(db, visited, n-2);
//         db[n] = result;
//         visited[n] = true;
//         return result;
//     }
// };
// @lc code=end

