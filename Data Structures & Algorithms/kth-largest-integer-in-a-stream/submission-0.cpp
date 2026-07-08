class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto it:nums){
            pq.push(it);
            
        }
        
    }
    
    int add(int val) {
      pq.push(val);
       while(pq.size()>size)pq.pop();
       return pq.top();
       
        
    }
};
