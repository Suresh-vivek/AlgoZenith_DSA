/*
355. Design Twitter
Medium
Topics
Companies

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

    Twitter() Initializes your twitter object.
    void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
    List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
    void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
    void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

 

Constraints:

    1 <= userId, followerId, followeeId <= 500
    0 <= tweetId <= 104
    All the tweets have unique IDs.
    At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.


*/


#include <bits/stdc++.h>
using namespace std;


class Twitter {
public:

    // user -> list of frirnds
    map<int , set<int>> friends ; // set is used to represent distinct friends

    // tweets  wuth timeline
    priority_queue<vector<int>> timeline;

    // variable to hold tweets number

    int cur =0;

    Twitter() {

        // inintializig variables
        friends.clear();
        cur =0;
        timeline = priority_queue<vector<int>>() ; // empty queue
        
    }
    
    void postTweet(int userId, int tweetId) {

        // add tweets in timeline
        timeline.push({cur++ , userId , tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {

        // ans vector
        vector<int> ans;

        priority_queue<vector<int>> usertimeline = timeline;
        int n =0;

        while(!usertimeline.empty() && n < 10){

                auto toptweet = usertimeline.top();
                usertimeline.pop();

                // check if tweet is from user or its frirnds

                if(toptweet[1]== userId or friends[userId].find(toptweet[1])!= friends[userId].end()){  // freinds[userId].count(toptweet[1])

                    ans.push_back(toptweet[2]);
                        
                }
        }

        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {

        // Adding list of friends
        friends[followerId].insert(followeeId);



        
    }
    
    void unfollow(int followerId, int followeeId) {

        // removing list of friends
        friends[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */