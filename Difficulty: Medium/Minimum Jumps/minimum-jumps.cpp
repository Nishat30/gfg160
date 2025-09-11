
class Solution {
  public:
    int solve(int i,vector<int>& arr,vector<int>& dp){
        if (i >= arr.size() - 1) return 0;  // If we reach or exceed last index, no jumps needed.
        if (arr[i] == 0) return INT_MAX / 2;;  // If stuck at a zero, return a large number (infinity).
        if(dp[i]!=-1) return dp[i];
        int result = INT_MAX;
        for (int idx = i + 1; idx <= i + arr[i] && idx < arr.size(); idx++) {
            result = min(result, 1 + solve(idx, arr, dp));
        }
        return dp[i]=result;
    }
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 1) return 0;          // Already at last index
        if (arr[0] == 0) return -1;    // Can't move anywhere

        int maxReach = arr[0];  // Farthest index reachable
        int steps = arr[0];     // Steps left in current jump
        int jumps = 1;          // We make the first jump from index 0

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached last index

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {  // Need to make another jump
                jumps++;
                if (i >= maxReach) return -1;  // Can't move further
                steps = maxReach - i;
            }
        }
        return -1; // If end is never reached
    }
};


