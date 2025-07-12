class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat_needed = 1, max_platforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        max_platforms = max(max_platforms, plat_needed);
    }

    return max_platforms;
    }
};
