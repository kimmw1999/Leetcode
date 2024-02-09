/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//leetcode solution
class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 10 tweets
        int count = 10;
        vector<int> result;
        
        // since postTweet pushes to the back, looping from back gets most recent
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }
            
            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];
            // add to result if they're following them or it's a tweet from themself
            if (following.find(followingId) != following.end() || followingId == userId) {
                result.push_back(tweetId);
                count--;
            }
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
private:
    // pairs: [user, tweet]
    vector<pair<int, int>> posts;
    // hash map: {user -> people they follow}
    unordered_map<int, unordered_set<int>> followMap;
};

// class Twitter {
// public:
//     Twitter() {
//         tweet_count = 0;
//     }
    
//     void postTweet(int userId, int tweetId) {
//         //{tweet_count, tweetId}
//         tweet_map[userId].push_back({tweet_count+1,tweetId});
//         tweet_count++;
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         priority_queue<pair<int, int>> pq;
//         vector<pair<int, int>> tweets;
//         for(int followee : follow_map[userId]) {
//             for(pair<int, int> tweet : tweet_map[followee]){
//                 pq.push(tweet);
//             }
//         }
//         for(pair<int, int> self_tweet : tweet_map[userId]) {
//             pq.push(self_tweet);
//         }
//         vector<int> result;
//         for(int i = 0; i < 10; i++) {
//             if(pq.empty()) {
//                 break;
//             }
//             int tw = pq.top().second;
//             pq.pop();
//             result.push_back(tw);
//         }
//         return result;
//     }
    
//     void follow(int followerId, int followeeId) {
//         vector<int> &followers = follow_map[followerId];
//         auto it = find(followers.begin(), followers.end(), followeeId);
//         if (it == followers.end()) {
//             follow_map[followerId].push_back(followeeId);
//         }
//         cout << followerId<<" followed " << followeeId << ": ";
//         for(int i : follow_map[followerId]) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
    
//     void unfollow(int followerId, int followeeId) {
//         vector<int> &followers = follow_map[followerId];
//         // Use iterator to find and erase followeeId from followers
//         auto it = find(followers.begin(), followers.end(), followeeId);
//         if (it != followers.end()) {
//             followers.erase(it);
//         }
//         cout << followerId<<" unfollowed " << followeeId << ": ";
//         for(int i : follow_map[followerId]) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }

// private:
//     unordered_map<int, vector<int>> follow_map;
//     unordered_map<int, vector<pair<int, int>>> tweet_map;
//     int tweet_count;
// };

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
int main() {
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    obj->getNewsFeed(1);
    obj->follow(1,2);
    obj->postTweet(2,6);
    obj->getNewsFeed(1);
    obj->unfollow(1,2);
    obj->getNewsFeed(1);
}
