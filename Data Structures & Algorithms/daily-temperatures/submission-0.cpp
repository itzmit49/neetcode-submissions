class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        vector<int> temp(t.size(), 0);

        stack<pair<int, int>> st;

        for (int i = 0; i < t.size(); i++) {

            while (!st.empty() && t[i] > st.top().first) {

                auto pr = st.top();
                st.pop();

                temp[pr.second] = i - pr.second;
            }

            st.push({t[i], i});
        }

        return temp;
    }
};