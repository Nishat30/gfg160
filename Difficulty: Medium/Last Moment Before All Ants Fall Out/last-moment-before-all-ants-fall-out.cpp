class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int miniRight = n;
        int maxLeft = 0;
        
        int elementInLeftArray = left.size();
        int elementInRightArray = right.size();
        
        for(int i = 0; i < elementInLeftArray ; i++)
        {
            maxLeft = max(maxLeft,left[i]);
        }
        
        for(int i = 0;i<elementInRightArray;i++)
        {
            miniRight = min(miniRight, right[i]);
        }
        
        int maxTime = max((n-miniRight),(maxLeft));
        return maxTime;
    }
};