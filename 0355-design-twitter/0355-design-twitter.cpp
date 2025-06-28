class Twitter {
public:

    int time;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        if(tweetMap[userId].size() > 10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        time--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        followMap[userId].insert(userId);
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const vector<pair<int, int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index].first, tweets[index].second, followeeId, index});
            }
        }
        while (!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const pair<int, int>& tweet = tweetMap[curr[2]][index - 1];
                minHeap.push({tweet.first, tweet.second, curr[2], index - 1});

            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
        
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