class Twitter {
public:

    unordered_map<int, vector<pair<int,int> > > user_tweets;
    unordered_map<int, unordered_set<int> > follows;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        user_tweets[userId].emplace_back(time, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed; feed.reserve(10);
        // most recent feeds will have largest time in our conventions, so we need to merge k sorted lists basically
        priority_queue<tuple<int,int,int,int> > maxheap;
        for (auto& user: follows[userId]){
            int idx = user_tweets[user].size() - 1;
            if (idx < 0) continue;
            auto& [t, tweetId] = user_tweets[user][idx];
            maxheap.emplace(t,tweetId,user,idx);
        }
        {
            int idx = user_tweets[userId].size() - 1;
            if (idx >= 0){
            auto& [t, tweetId] = user_tweets[userId][idx];
            maxheap.emplace(t,tweetId,userId,idx);}
        }
        while (!maxheap.empty() && feed.size() < 10){
            auto [t, tweetId, user, idx] = maxheap.top();
            maxheap.pop();
            feed.push_back(tweetId);
            idx--;
            if (idx >= 0){
                auto [t1, tweetId1] = user_tweets[user][idx];
                maxheap.emplace(t1,tweetId1,user,idx);
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
