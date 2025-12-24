class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int cnt=0;
        for(int num:arr)
        {
            if(num<=x)
            {
                cnt++;
            }
        }
        return cnt;
    }
};