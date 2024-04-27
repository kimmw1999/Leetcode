/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        // unordered_set<int> visited;
        // while(true) {
        //     if(n==1) {
        //         return true;
        //     }
        //     if(visited.find(n) != visited.end()) {
        //         return false;
        //     }
        //     visited.insert(n);
        //     int next = 0;
        //     while(n > 0) {
        //         next += pow((n%10), 2);
        //         n = (int)(n/10);
        //     }
        //     n = next;
        // }
        int slow=n;
        int fast = getNext(n);

        while(slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast==1;
    }

private:
    int getNext(int n) {
        int next = 0;
        while(n > 0) {
            int digit = n % 10;
            next += pow(digit, 2);
            n /= 10;
        }
        return next;
    }
};
// @lc code=end

