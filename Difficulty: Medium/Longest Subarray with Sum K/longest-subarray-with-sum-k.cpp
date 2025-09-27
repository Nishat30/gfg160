class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int res=0;
        int prefSum=0;
        
        for(int i=0;i<arr.size();++i){
            prefSum+=arr[i];
            
            if(prefSum==k){
                res=i+1;
            }
            else if(mp.find(prefSum-k)!=mp.end()){
                res=max(res,i-mp[prefSum-k]);
            }
            if(mp.find(prefSum)==mp.end()){
                mp[prefSum]=i;
            }
        }
        return res;
    }
};
