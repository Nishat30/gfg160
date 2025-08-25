class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), cur = (n-1)/2;
        sort(arr.begin(), arr.end());
        
        if(n%2 == 0 && arr[cur+1]-arr[cur] >= k) return (arr[cur+1] + arr[cur] + k)/2;
        
        int len = 1;
        while(k) {
            while(cur < n-1 && arr[cur] == arr[cur+1]) cur++, len++;
            
            
            if(cur == n-1)  return arr[cur] + k / len;
            
            int diff = arr[cur+1] - arr[cur];
            
            if(k >= diff * len) cur++, k -= diff * len, len++;
            else return arr[cur] + k / len;
            
        }
        
        return arr[cur];
    }
};