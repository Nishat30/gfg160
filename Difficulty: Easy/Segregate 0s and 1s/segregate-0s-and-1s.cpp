// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            while(arr[i]==0){
                i++;
            }
            if(arr[j]==1){
                j--;
            }
            else if(arr[i]==1 && arr[j]==0){
                swap(arr[i],arr[j]);
            }
        }
    }
};