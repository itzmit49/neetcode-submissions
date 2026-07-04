class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int idx1=(m+n)/2-1;
        int idx2=(m+n)/2;
       int el1=-1,el2=-1;
       int i=0,j=0;
       int cnt=0;
       while(i<m&&j<n){
        int val;
        if(nums1[i]<nums2[j]){
            val=nums1[i++];
        }else val=nums2[j++];
        if(cnt==idx1)el1=val;
        if(cnt==idx2)el2=val;
        cnt++;
       }
       while(i<m){
        int val=nums1[i++];
         if(cnt==idx1)el1=val;
        if(cnt==idx2)el2=val;
        cnt++;
       }
          while(j<n){
        int val=nums2[j++];
         if(cnt==idx1)el1=val;
        if(cnt==idx2)el2=val;
        cnt++;
       }
       if((m+n)%2==1)return el2;
       return (el1+el2)/2.0;
        
    }
};
