class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>count1;
        for(auto it:s1)count1[it]++;
        int need=count1.size();
        for(int i=0;i<s2.size();i++){
            unordered_map<char,int>count2;
            int curr=0;
            for(int j=i;j<s2.size();j++){
              char c=s2[j];
              count2[c]++;
              if(count1[c]<count2[c])break;
              if(count1[c]==count2[c])curr++;
              if(curr==need)return true;
            }
        }
        return false;
    }
};
