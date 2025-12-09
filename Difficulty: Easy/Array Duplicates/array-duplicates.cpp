class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i:arr){
            mp[i]++;
        }
        vector<int> ans;
        for(auto &p : mp){
            if(p.second > 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};