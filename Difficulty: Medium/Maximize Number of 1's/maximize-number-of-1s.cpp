class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
    int res = 0;

    // Start and end pointer of the window 
    int start = 0, end = 0; 
    
    // Counter to keep track of zeros in current window
    int cnt = 0;
    
    while (end < arr.size()) {
        if (arr[end] == 0)
            cnt++;
        
        // Shrink the window from left if number of 
        // zeroes are greater than k
        while (cnt > k) {
            if (arr[start] == 0)
                cnt--;
                
            start++;
        }
        
        res = max(res, (end - start + 1));
        
        // Increment end pointer to expand the window
        end++; 
    }
    
    return res; 
    }
};

