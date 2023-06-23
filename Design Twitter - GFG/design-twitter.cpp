//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    // Initialize your data structure here
    int time;
    unordered_map<int,unordered_set<int>>follows;
    unordered_map<int,vector<pair<int,int>>>tweet;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        if(tweet.find(userId)!=tweet.end()){
            for(auto tweets:tweet[userId]){
                pq.push(tweets);
                if(pq.size()>10)pq.pop();
            }

        }

        if(follows.find(userId)!=follows.end()){
            for(auto followeeId:follows[userId]){
                if(tweet.find(followeeId)!=tweet.end()){
                    for(auto tweets:tweet[followeeId]){
                        pq.push(tweets);
                        if(pq.size()>10)pq.pop();
                    }
                }
            }
        }
        while(!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follows.find(followerId) != follows.end())
        {
            follows[followerId].erase(followeeId);
        }
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends