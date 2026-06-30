class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //if (s.size() == 0) return 0;

        unordered_set<char> st;
        int i = 0;
        int ct = 0;
        for (int j = 0; j < s.size(); j++) {
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ct = max(ct, j - i + 1);
        }
        return ct;
    }
};
