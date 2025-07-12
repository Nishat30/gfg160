class Solution {
  public:
    int dfs(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (row < 0 || row >= mat.size() || col >= mat[0].size()) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        int right = dfs(row, col + 1, mat, dp);
        int right_up = dfs(row - 1, col + 1, mat, dp);
        int right_down = dfs(row + 1, col + 1, mat, dp);

        return dp[row][col]= mat[row][col] + max({right, right_up, right_down});
    }

    int maxGold(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int max_coin = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++) {
            max_coin = max(max_coin, dfs(i, 0, mat, dp));
        }
        return max_coin;
    }
};