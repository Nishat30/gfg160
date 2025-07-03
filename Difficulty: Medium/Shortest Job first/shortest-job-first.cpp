// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int sum=0;
        vector<int> wt;
        for(int i:bt){
            wt.push_back(sum);
            sum+=i;
        }
        int s=accumulate(wt.begin(),wt.end(),0);
        int n=bt.size();
        return s/n;
    }
};