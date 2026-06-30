class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return "";
        unordered_map<char,int>count1,window;
        for(auto it:t)count1[it]++;

        int have=0;
        int  need=count1.size();
        pair<int,int>res={-1,-1};
        int reslen=INT_MAX;
        int l=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(count1.count(c)&&window[c]==count1[c])have++;
            while(have==need){
                if((r-l+1)<reslen){
                    reslen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;
                if(count1.count(s[l])&&window[s[l]]<count1[s[l]])have--;
                l++;
            }
        }
return reslen==INT_MAX?"":s.substr(res.first,reslen);
    }
};
