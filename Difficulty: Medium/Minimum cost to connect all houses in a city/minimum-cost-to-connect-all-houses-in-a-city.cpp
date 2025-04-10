//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size();
       
       vector<pair<int,int>> adj[n];
       
       for(int i=0;i<n;i++){
            int x1 = houses[i][0];
            int y1 = houses[i][1];
           for(int j=i+1;j<n;j++){
                int x2 = houses[j][0];
                int y2 = houses[j][1];
               int dist = abs(x1-x2) + abs(y1-y2);
               adj[i].push_back({dist,j});
               adj[j].push_back({dist,i});
           }
       }
        
        
        //prims's algorithm
        int res=0;
        set<int> vis;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min-heap
        
        pq.push({0,0}); // dist,point
        
        while(vis.size()<n){
            
            auto t = pq.top();
            int dist = t.first;
            int node = t.second;
            pq.pop();
            
            
            if(vis.find(node)!=vis.end()) continue;
            
            vis.insert(node);
            res+=dist;
            
            for(auto it : adj[node]){
                int d = it.first;
                int adjNode = it.second;
                if(vis.find(adjNode)!=vis.end()) continue;
                pq.push({d,adjNode});
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends