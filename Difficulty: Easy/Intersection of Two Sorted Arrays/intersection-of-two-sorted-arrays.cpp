class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(), m=b.size();
        int i=0, j=0;
        
        vector<int>ans;
        
        while(i<n && j<m){
            if(a[i]==b[j]){
                int t=a[i];
                while(i<n && a[i]==t){
                    i++;
                }
                while(j<m && b[j]==t){
                    j++;
                }
                ans.push_back(t);
            }else if(a[i]<b[j]){
                i++;
            }else j++;
        }
        
        return ans;
    }
};