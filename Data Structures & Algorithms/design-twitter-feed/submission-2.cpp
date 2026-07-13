
class Twitter {
public:
int time;
   unordered_map<int,unordered_set<int>>followMap;
   unordered_map<int,vector<pair<int,int>>>tweetmp;
    Twitter() :time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmp[userId].push_back({time++,tweetId});

        
    }
    
    vector<int> getNewsFeed(int userId) {
         priority_queue<pair<int,int>> pq;

    for (auto it : tweetmp[userId]) {
        pq.push({it.first, it.second});
    }

    for (int id : followMap[userId]) {
        for (auto it : tweetmp[id]) {
            pq.push({it.first, it.second});
        }
    }

    vector<int> ans;

    while (!pq.empty() && ans.size() < 10) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
      
    }
    
    void follow(int followerId, int followeeId) {
     if(followerId!=followeeId)   followMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
       followMap[followerId].erase(followeeId);
        
    }
};
