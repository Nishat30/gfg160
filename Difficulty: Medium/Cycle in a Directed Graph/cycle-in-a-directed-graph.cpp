//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> indegree(V, 0); 
    
  
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                indegree[v]++; 
            }
        } 
        queue<int> q;
        int n=adj.size();
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            ans.push_back(i);
            for(auto& idx:adj[i]){
                indegree[idx]--;
                if(indegree[idx]==0){
                    q.push(idx);
                }
            }
        }
        if(ans.size()==V){
            return false; //this means topo sort is done mtlb the graph is acylic
        }else{
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends