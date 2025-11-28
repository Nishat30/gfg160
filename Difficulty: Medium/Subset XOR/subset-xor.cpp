class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
         int XOR = 0;
        for(int i=0; i<=n; i++)
        XOR = XOR^i;
        int exclude = XOR^n;
        vector<int> ans;
        for(int i=1; i<=n; i++)
        {
            if(i!=exclude)
            ans.push_back(i);
        }
        return ans;
    }
};
