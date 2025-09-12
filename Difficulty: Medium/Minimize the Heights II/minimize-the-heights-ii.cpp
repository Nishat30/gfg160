// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
    if (n == 1) return 0; // If there's only one tower, the difference is always 0.

    // Sort the array to analyze height differences systematically.
    sort(arr.begin(), arr.end());

    // Initial difference between the tallest and shortest tower.
    int diff = arr[n - 1] - arr[0];

    // Initialize minimum and maximum heights.
    int minHeight, maxHeight;

    // Iterate through the array and compute possible differences.
    for (int i = 1; i < n; i++) {
        if (arr[i] - k < 0) continue; // Skip if reducing height by k results in negative.

        minHeight = min(arr[0] + k, arr[i] - k);   // Minimum possible height after modification.
        maxHeight = max(arr[n - 1] - k, arr[i - 1] + k); // Maximum possible height after modification.

        // Update the minimum difference.
        diff = min(diff, maxHeight - minHeight);
    }

    return diff;
    }
};
