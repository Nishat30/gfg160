class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==k){
                return i;
            }
            if(arr[i]>k){
                return i;
            }
        }
        return arr.size();
    }
};