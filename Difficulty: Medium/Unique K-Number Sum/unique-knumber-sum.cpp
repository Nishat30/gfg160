class Solution {
  public:
    void get(vector<vector<int>> & ans, vector<int> a, int n, int k, int j)
    {
        if (k == a.size() && n == 0) {
            ans.push_back(a);
            return;
        }
        else {

            for (int i = j; i <= 9; i++) {
                a.push_back(i);
                get(ans, a, n-i, k, i+1);
                a.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        get(ans, {}, n, k, 1);
        return ans;
    }
};