class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>mpp;
        int count = 0;
        int st = 0,end=0;
        while(end<n){
           mpp[arr[end]]++;
           while(mpp.size()>k){
               mpp[arr[st]]--;
               if(mpp[arr[st]] == 0) mpp.erase(arr[st]);
               st++;
           }
           count = count+(end-st+1);
           end++;
        }
        return count;
    }
};