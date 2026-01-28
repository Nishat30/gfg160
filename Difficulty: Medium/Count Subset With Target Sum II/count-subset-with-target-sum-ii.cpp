class Solution {
  public:
  unordered_map<int , int>mp1 , mp2;
    
    void Generate(int i , int curr , vector<int> &arr, int turn){
        int n = arr.size();
        if(i == n){
            if(turn == 1)
                mp1[curr]++;
            else
                mp2[curr]++;
            return;
        }
        Generate(i + 1 , curr , arr , turn);
        Generate(i + 1 , curr + arr[i] , arr , turn);
    }
    int countSubset(vector<int> &arr, int k) {
        // code here
        vector<int>v1 , v2;
        mp1.clear();
        mp2.clear();
        int n = arr.size() , ans = 0;
        for(int i = 0; i < n; i++){
            if(i & 1)
                v1.push_back(arr[i]);
            else    
                v2.push_back(arr[i]);
        }
        Generate(0 , 0 , v1 , 1);
        Generate(0 , 0 , v2 , 2);
        
        for(auto &it : mp1){
            int s1 = it.first , cnt1 = it.second;
            int s2 = k - s1 , cnt2 = mp2[s2];
            ans += (cnt1 * cnt2);
        }
        return ans;
    }
};