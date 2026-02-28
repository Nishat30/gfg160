class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int i = 0;                     
        int j = arr2.size() - 1;       
        int first = 0, second = 0;
        int minDiff = INT_MAX;

        while(i < arr1.size() && j >= 0){
            int sum = arr1[i] + arr2[j];
            int diff = abs(x - sum);
            if(diff < minDiff){
               minDiff = diff;
               first = arr1[i];
               second = arr2[j];
            }
            if(sum > x)
               j--;      // dec sum
            else
               i++;      // inc sum
        }
        return {first, second};
    }
};