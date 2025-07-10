// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    bool static comp(pair<int,int> item1,pair<int,int> item2){
        return ((double)((double) item1.first)/(double)(((double) item1.second))>((double) item2.first)/((double) item2.second));
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>> item;
        int n=val.size();
        for(int i=0;i<n;i++){
            item.push_back({val[i],wt[i]});
        }
        sort(item.begin(),item.end(),comp);
        double ans=0.0;
        int curr=0;
        for (int i = 0; i < n; i++) {
         if (curr + item[i].second <= capacity) {
            curr += item[i].second;
            ans += item[i].first;
         } else {
            int remain = capacity - curr;
            ans += (item[i].first / (double) item[i].second) * (double) remain;
            break;
         }
      }
      return ans;
    }
};
