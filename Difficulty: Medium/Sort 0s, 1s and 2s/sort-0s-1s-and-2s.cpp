class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // Initialize pointers
        int low = 0, mid = 0, high = n - 1;
        
        // Traverse the array using the Dutch National Flag Algorithm
        while (mid <= high) {
            switch(arr[mid]) {
                // Case when the element is 0
                case 0: 
                    swap(arr[low++], arr[mid++]);  // Swap 0 to the low region and move both pointers
                    break;
                
                // Case when the element is 1
                case 1: 
                    mid++;  // 1 is already in the correct region, so just move mid forward
                    break;
                
                // Case when the element is 2
                case 2: 
                    swap(arr[mid], arr[high--]);  // Swap 2 to the high region and move high backward
                    break;
            }
        }
    }
};