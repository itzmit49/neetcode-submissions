class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++)freq[tasks[i]-'A']++;

        priority_queue<int>pq;
        for(auto  it:freq){
            if(it>0)pq.push(it);
        }
        queue<pair<int,int>>q;
        int time=0;
        while(!pq.empty()||!q.empty()){
            time++;
            if(!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                if(f>0){
                    q.push({f,time+n});
                }


            }
             if (!q.empty() && q.front().second == time) {

                pq.push(q.front().first);
                q.pop();
            }
        }

      return time;
        
    }
};