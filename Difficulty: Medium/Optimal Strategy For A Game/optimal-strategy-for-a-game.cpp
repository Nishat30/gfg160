class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                
                if (i == j) {
                    dp[i][j] = arr[i];
                }
                // If two coins
                else if (j == i + 1) {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else {
                    long long take_i = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    long long take_j = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
                    dp[i][j] = max(take_i, take_j);
                }
            }
        }

        return dp[0][n-1];
    }
};
