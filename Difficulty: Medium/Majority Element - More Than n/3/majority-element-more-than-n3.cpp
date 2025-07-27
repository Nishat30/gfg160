class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int>ans;
        int n = arr.size();
        int m[1000000] = {0};
        for(int i = 0;i<arr.size();i++){
            m[arr[i]] += 1;
        }
        for(int i = 0; i<n;i++){
            if(m[arr[i]] > n/3){
                ans.push_back(arr[i]);
                m[arr[i]] = 0;
            }
        }sort(ans.begin(),ans.end());
        return ans;
    }
};