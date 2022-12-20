class Twitter {
    long long time = 1;
    unordered_map<int, deque<pair<int, int>>> tweet;
    unordered_map<int, unordered_set<int>> fol;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_front({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> tweetId;
        int index = 0;
        
        while( index < tweet[userId].size() && index < 10){
            pq.push(tweet[userId].at(index));
            index++;
        }
        for(auto id : fol[userId]){
            index = 0;
            while((index < tweet[id].size()) && index < 10){
                pq.push(tweet[id].at(index));
                index++;
            }
        }
        
        while(!pq.empty() && tweetId.size() < 10){
            tweetId.push_back(pq.top().second);
            pq.pop();
        }
        return tweetId;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
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