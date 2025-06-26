class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        priority_queue<int>pq;
        vector<int>v(26,0);
        for(auto &b: s){v[b-'a']++;}
        for(auto &b: v){
            if(b!=0){pq.push(b);}
        }
        while(k--){
            int x=pq.top(); pq.pop();
            x--;
            pq.push(x);
        }
        int ans=0;
        while(pq.size()){
            ans+=(pq.top()*pq.top()); pq.pop();
        }
        return ans;
    }
};