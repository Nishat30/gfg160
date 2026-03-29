
class Solution {
  public:
    const int mod=1e9+7;
    int solve(int idx, int d,vector<vector<int>>& dp,vector<int>& arr){
        if(idx==0){
            if(d==0 && arr[0]==0)return 2;
            if(d==0 || d==arr[0]) return 1;
            return 0;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int not_take=solve(idx-1,d,dp,arr);
        int take=0;
        if(arr[idx]<=d){
            take=solve(idx-1,d-arr[idx],dp,arr);}
        return dp[idx][d]=(take+not_take)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        //tabulation
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int> (target+1,0));
        // if(arr[0]==0) dp[0][0]=2;
        // else dp[0][0]=1;
        // //num[0]=0
        // if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
        // for(int idx=1;idx<n;idx++){
        //     for(int sum=0;sum<=target;sum++){
        //         int not_take=dp[idx-1][sum];
        //         int take=0;
        //         if(arr[idx]<=sum){
        //           take=dp[idx-1][sum-arr[idx]];}
        //         dp[idx][sum]=(take+not_take)%mod;
        //     }
        // }
        // return dp[n-1][target];
        
        //space optimisation
        vector<int> prev(target+1,0), curr(target+1,0);
        if(arr[0]==0) prev[0]=2;
        else prev[0]=1;
        //num[0]=0
        if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;
        for(int idx=1;idx<n;idx++){
            for(int sum=0;sum<=target;sum++){
                int not_take=prev[sum];
                int take=0;
                if(arr[idx]<=sum){
                  take=prev[sum-arr[idx]];}
                curr[sum]=(take+not_take)%mod;
            }
            prev=curr;
        }
        return prev[target];
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int total_sum=0;
        for(auto&it:arr)total_sum+=it;
        if(total_sum-d<0 || (total_sum-d)%2) return 0;
        return perfectSum(arr,(total_sum-d)/2);
    }
};

