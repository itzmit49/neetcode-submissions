class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        while (!q.empty()) {

            auto [w, step] = q.front();
            q.pop();

            if (w == endWord)
                return step;

            for (int i = 0; i < w.size(); i++) {
                char ch = w[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    if (c == ch) continue;

                    w[i] = c;

                    if (st.find(w) != st.end()) {
                        st.erase(w);
                        q.push({w, step + 1});
                    }
                }

                w[i] = ch;
            }
        }

        return 0;
    }
};