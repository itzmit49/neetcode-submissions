class Solution {
public:
   
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
      for(auto it:stones)pq.push(it);
      // 6 4 3 2 2
      // 6 4 =  3 222
      // 
      while(pq.size()!=1){
        auto x=pq.top();
        pq.pop();
      //  if(pq.size()==1)return pq.top();
        auto y=pq.top();
        pq.pop();
        if(x==y)pq.push(0);
        else if(x>y)pq.push(x-y);
        else pq.push(y-x);

      }
      return pq.top();
        
    }
};
