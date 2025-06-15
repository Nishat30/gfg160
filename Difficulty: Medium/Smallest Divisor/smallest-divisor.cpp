class Solution {
  public:
    int solve(vector<int>& arr,int ans){
        int sum=0;
        for(int i:arr){
            sum+=ceil((double)i/ans);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = solve(arr, mid);

            if (sum <= k) {
                result = mid;  // mid is a possible answer
                high = mid - 1;  // try to find smaller
            } else {
                low = mid + 1;  // mid too small, increase
            }
        }

        return result;
    }
};
