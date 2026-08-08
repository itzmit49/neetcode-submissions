class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>freq;
        for(auto it:s)freq[it]++;
        vector<int>ans;
        int cnt=0;
        string a="";
        for(int i=0;i<s.size();i++){
            a+=s[i];
            cnt++;
            freq[s[i]]--;
            bool flag=true;
            for(auto it:a){
                if(freq[it]!=0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                a="";
                ans.push_back(cnt);
                cnt=0;
            
            }
            

        }
        return ans;
        
    }
};