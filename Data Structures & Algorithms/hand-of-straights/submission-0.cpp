class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        for (int x : hand)
            freq[x]++;

        for (auto it : freq) {
            int card = it.first;
            int cnt = it.second;

            if (cnt == 0)
                continue;

            for (int i = 0; i < groupSize; i++) {
                if (freq[card + i] < cnt)
                    return false;

                freq[card + i] -= cnt;
            }
        }

        return true;
    }
};