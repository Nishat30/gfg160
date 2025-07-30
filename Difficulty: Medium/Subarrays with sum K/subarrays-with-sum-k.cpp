class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> prefixSum;
        int sum = 0;
        int count =0;
        
        for(int i=0;i<arr.size();i++){
            prefixSum[sum]++;
            sum+=arr[i];
            count+=prefixSum[sum-k];
        }
        return count;
    }
};