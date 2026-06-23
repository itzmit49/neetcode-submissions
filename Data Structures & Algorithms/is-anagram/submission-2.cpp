class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
      int mp[26]={0};
        for(auto x:s)mp[x-'a']++;
        for(auto x:t){
            
            mp[x-'a']--;
            if(mp[x-'a']<0)return false;
        }
        return true;
        
        
    }
};
