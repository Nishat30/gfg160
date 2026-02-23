class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>m;
        vector<int>ans;
        
        for(int i=0;i<a.size();i++){
            if(m.count(a[i])==0){
                m[a[i]]++;
                ans.push_back(a[i]);
            }
        }
        
        for(int i=0;i<b.size();i++){
            if(m.count(b[i])==0){
                m[b[i]]++;
                ans.push_back(b[i]);
            }
        }
        
        return ans;
    }
};