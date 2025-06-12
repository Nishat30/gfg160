class Solution {
  public:
    typedef pair<int, int> p;
    struct comp {
        bool operator()(p& p1, p& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            } else {
                return p1.first > p2.first;
            }
        }
    } ;
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n = arr.size();
        vector<int> newarr(n);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(arr[i] <= x){
                newarr[i] = x - arr[i];
            } else {
                newarr[i] = arr[i] - x;
            }
        }
        priority_queue<p, vector<p>, comp> pq;
        
        int count = 1;
        for(int i = 0; i < n; i++){
            pq.push({newarr[i], i});
        }
        
        while(!pq.empty() && count<=k){
            if(pq.top().first == 0){
                pq.pop();
            }
            else if(pq.top().first != 0){
                ans.push_back(arr[pq.top().second]);
                pq.pop();
                count++;
            }
        }
        return ans;
    }
};