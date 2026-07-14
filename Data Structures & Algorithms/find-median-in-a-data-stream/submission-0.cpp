class MedianFinder {
public:
  vector<int>nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
        
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        
        if(nums.size()%2==1){
            return double(nums[nums.size()/2]);

        }
        else {
            int a=nums[nums.size()/2-1];
            int b=nums[nums.size()/2];
            return (a+b)/2.0;
        }
        
    }
};
