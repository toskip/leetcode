//too slow
class Twitter {
public:
    /** Initialize your data structure here. */
    vector<pair<int,int> > twitters;
    map<pair<int,int>,bool> follows;
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twitters.push_back(make_pair(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        int n = twitters.size();
        for(int i = n-1;i>=0;i--)
        {
            if(twitters[i].first==userId||follows[make_pair(userId,twitters[i].first)])
            {
                result.push_back(twitters[i].second);
                if(result.size()==10) break;
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[make_pair(followerId,followeeId)] = true;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[make_pair(followerId,followeeId)] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
