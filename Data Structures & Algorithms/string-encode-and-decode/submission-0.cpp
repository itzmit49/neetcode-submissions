class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto it:strs){
          s.append(to_string(it.size()));
          s.push_back('#');
          s.append(it);
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            ans.push_back(s.substr(i,len));
            i=j;
        }
        return ans;
        

    }
};
