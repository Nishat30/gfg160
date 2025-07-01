class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.length();
        if (k > n) return 0;

        unordered_map<char, int> freq;
        int unique = 0, ans = 0;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            if (++freq[s[i]] == 1)
                unique++;
        }
        if (unique == k - 1) ans++;

        // Slide the window
        for (int i = k; i < n; i++) {
            // Remove leftmost
            char left = s[i - k];
            if (--freq[left] == 0)
                unique--;
            
            // Add rightmost
            char right = s[i];
            if (++freq[right] == 1)
                unique++;

            if (unique == k - 1)
                ans++;
        }

        return ans;
    }
};