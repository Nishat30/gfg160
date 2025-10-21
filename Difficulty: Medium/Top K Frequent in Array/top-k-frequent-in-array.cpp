class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        map<int,int> mp;
        for(int i = 0;i<arr.size();i++)mp[arr[i]]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(pair<int,int> pr: mp){
            pq.push({pr.second, pr.first});
            if(pq.size()>k)pq.pop();
        }
        
        vector<int> result(k);
        for(int i = 0;i<k;i++){
            result[i]=pq.top().second;
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
