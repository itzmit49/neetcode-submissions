class Solution {
public:
    bool isValid(string &a, string &b) {
        int ct = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) ct++;
        }
        return ct == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        bool found = false;
        for (auto &w : wordList) {
            if (w == endWord) {
                found = true;
                break;
            }
        }
        if (!found) return 0;

        queue<string> q;
        q.push(beginWord);

        int n = wordList.size();
        vector<int> vis(n, 0);
        int step = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string s = q.front();
                q.pop();

                if (s == endWord) return step;

                for (int i = 0; i < n; i++) {
                    if (!vis[i] && isValid(wordList[i], s)) {
                        vis[i] = 1;
                        q.push(wordList[i]);
                    }
                }
            }
            step++;
        }

        return 0;
    }
};