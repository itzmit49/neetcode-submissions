class Solution {
public:
    unordered_map<int, int> mp;

    bool solve(int n) {
        if(n == 1)
            return true;

        if(mp.find(n) != mp.end())
            return false;

        mp[n] = 1;

        int num = 0;

        while(n > 0) {
            int rem = n % 10;
            num += rem * rem;
            n /= 10;
        }

        return solve(num);
    }

    bool isHappy(int n) {
        return solve(n);
    }
};