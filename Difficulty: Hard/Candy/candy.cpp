class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        int cnt = 0;
        vector<pair<int,int>> v;
        for(int i = 0;i<arr.size();i++){
            v.push_back({arr[i],1});
        }
        for(int i = 1;i<arr.size();i++){
            if(arr[i] > arr[i-1]){
                v[i].second = v[i-1].second+1;
            }
            else if(arr[i] == arr[i-1]){
                continue;
            }
            else{
                if(v[i-1].second > v[i].second){
                    continue;
                }
                else{
                   v[i-1].second = v[i].second+1;
                }
            }
        }
        for(int i = n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                if(v[i].second > v[i+1].second){
                    continue;
                }
                else{
                    v[i].second = v[i+1].second+1;
                }
            }
            else if(arr[i] == arr[i+1]){
                continue;
            }
            else{
                if(v[i+1].second > v[i].second){
                    continue;
                }
                else{
                   v[i+1].second = v[i].second+1;
                }
            }
        }
        for(int i = 0;i<v.size();i++){
            cnt += v[i].second;
        }
        return cnt;
    }
};
