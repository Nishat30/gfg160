//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    int dfs(int idx,char arr[], int n, int k,vector<bool>& visited){
        if (idx >= n) return 0;
        if (visited[idx]) return dfs(idx + 1, arr, n, k, visited);
        
        if (arr[idx] == 'P') {
            for (int i = max(0, idx - k); i <= min(n - 1, idx + k); i++) {
                if (arr[i] == 'T' && !visited[i]) {
                    visited[i] = true;
                    visited[idx] = true;
                    return 1 + dfs(idx + 1, arr, n, k, visited);
                }
            }
        }
        return dfs(idx + 1, arr, n, k, visited);
    }
    int catchThieves(char arr[], int n, int k) 
    {
        vector<bool> visited(n,false);
        return dfs(0,arr,n,k,visited);
    }
};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	
cout << "~" << "\n";
}
	return 0; 
} 


// } Driver Code Ends