class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
   
        vector<int> b = arr;
        sort(b.begin(), b.end());
        
      
        vector<long long> C(n + 1, 0);
        C[0] = C[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                C[i] += C[j] * C[i - j - 1];
            }
        }
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
         
            int idx = find(b.begin(), b.end(), arr[i]) - b.begin();
            
            int left = idx;
            int right = n - idx - 1;
            
            ans.push_back(C[left] * C[right]);
        }
        
        return ans;
    }
};