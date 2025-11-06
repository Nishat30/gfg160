class Solution {
  public:
    int BS(int idx,int target,vector<vector<int>> &jobs){
        int n=jobs.size();
        int result=n;
        int s=idx,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(jobs[mid][0]>=target){
              result= mid;
               e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return result;
    }
    int solve(int i,vector<vector<int>> &jobs){
        if(i>=jobs.size()) return 0;
        int inc=0;
        int nextIdx=BS(i+1,jobs[i][1],jobs);
        inc=jobs[i][2]+solve(nextIdx,jobs);
        int exc=solve(i+1,jobs);
        return max(inc,exc);
    }
    int solveMem(int i,vector<vector<int>> &jobs,vector<int>&dp){
        if(i>=jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=0;
        int nextIdx=BS(i+1,jobs[i][1],jobs);
        inc=jobs[i][2]+solveMem(nextIdx,jobs,dp);
        int exc=solveMem(i+1,jobs,dp);
        return dp[i]=max(inc,exc);
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(),jobs.end());
        // return solve(0,jobs);
        vector<int>dp(jobs.size()+1,-1);
        return solveMem(0,jobs,dp);
        
    }
};
