//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        map<int, vector<pair<int, int>>> adj;
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto& nbr : adj[node]) {
                int next_node = nbr.first;
                int edge_weight = nbr.second;
                if (dist[node] + edge_weight < dist[next_node]) {
                    dist[next_node] = dist[node] + edge_weight;
                    q.push(next_node);
                }
            }
        }
        for(auto &a : dist)
            if(a==INT_MAX)a = -1;
        return dist ;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends