class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        vector<int> suf(n);
        suf[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suf[i] = min(arr[i], suf[i+1]);
        }
        for (int i = 0; i < n; i++) {
            if (i == n-1 || suf[i+1] >= arr[i]) {
                ans[i] = -1;
                continue;
            }
            int lo = i+1, hi = n-1, best = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (suf[mid] < arr[i]) {
                    best = mid;      // valid, but try farther right
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans[i] = best;
        }
        return ans;
    }
};