// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int j = 0;            // Pointer for the array
        int cnt = 0;          // Counter for missing numbers
    
        for (int i = 1; ; i++) {
            if (j < arr.size() && i == arr[j]) {
              j++;
            } else {
              cnt++;
              if (cnt == k) {
                return i;
            }
        }
    }
    }
};
