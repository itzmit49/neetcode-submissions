class Solution {
    struct Node {
        Node* links[26] = {nullptr};
        bool flag = false;

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root = new Node();
    vector<int> dp;

public:
    void insert(string &s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->containsKey(ch))
                node->put(ch, new Node());

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool solve(int idx, string &s) {
        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        Node* node = root;

        for (int j = idx; j < s.size(); j++) {
            char ch = s[j];

            if (!node->containsKey(ch))
                break;

            node = node->get(ch);

            if (node->isEnd() && solve(j + 1, s))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict)
            insert(word);

        dp.assign(s.size(), -1);

        return solve(0, s);
    }
};