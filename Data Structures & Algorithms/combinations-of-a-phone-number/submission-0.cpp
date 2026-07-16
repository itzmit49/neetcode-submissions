
class Solution {
public:
   unordered_map<int, string> mp = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};
vector<string>ans;
    void solve(int idx,string& digits,string &curr){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letter=mp[digits[idx]-'0'];
        for(auto c:letter){
            curr.push_back(c);
            solve(idx+1,digits,curr)
;
curr.pop_back();        }
    }
    vector<string> letterCombinations(string digits) {
       if(digits.empty())return {};
       string curr="";
       solve(0,digits,curr);
       return ans;
        
    }
};
