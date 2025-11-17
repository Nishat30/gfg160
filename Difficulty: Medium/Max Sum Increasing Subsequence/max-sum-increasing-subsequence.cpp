class Solution {
  public:
    int maxSum(vector<int>& arr,int i,int j,vector<vector<int>>&dp){
        int n=arr.size();
        //base case
        if(i==n) return 0; 
        if(dp[i][j+1]!=-1)            
            return dp[i][j+1];
        int include=0;                          
        if(j==-1||arr[i]>arr[j]){
            include=arr[i]+maxSum(arr,i+1,i,dp);
        }
        int Notinclude=maxSum(arr,i+1,j,dp);
        return dp[i][j+1]=max(include,Notinclude);
    }
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return maxSum(arr,0,-1,dp);
    }
};