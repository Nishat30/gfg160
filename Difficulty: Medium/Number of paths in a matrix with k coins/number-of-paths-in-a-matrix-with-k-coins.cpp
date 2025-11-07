class Solution {
  public:
    int solve(int row,int col,int n,int m,vector<vector<int>>& mat, int k,vector<vector<vector<int>>>& dp){
        if(k<0 || row<0 || col<0 || row>=n || col>=m)return 0;
        if (row==n-1 && col==m-1) {
            return k==mat[row][col];
        }
        if(dp[row][col][k] != -1){
            return dp[row][col][k];
        }
        int right = solve(row, col+1, n, m, mat, k-mat[row][col], dp);
        int down = solve(row+1, col, n, m, mat, k-mat[row][col], dp);
        
        return dp[row][col][k] = right+down;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int cnt=0;
        vector<vector<vector<int>>> dp(mat.size(),vector<vector<int>>(mat[0].size(), vector<int>(k+1, -1)));
        return solve(0,0,mat.size(),mat[0].size(),mat,k,dp);
    }
};