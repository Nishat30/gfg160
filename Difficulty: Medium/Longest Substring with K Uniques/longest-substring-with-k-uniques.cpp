class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int len = -1;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;

            while (mp.size() > k && prev <= i) {
                mp[s[prev]]--;
                if (mp[s[prev]] == 0) {
                    mp.erase(s[prev]);
                }
                prev++;
            }

            if (mp.size() == k) {
                len = max(len, i - prev + 1);
            }
        }

        return len;
    }
};
