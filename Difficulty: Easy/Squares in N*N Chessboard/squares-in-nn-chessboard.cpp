//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        long long ans=0;
        int n=N;
        for(int i=1;i<=n;i++){
            ans+=N*N;
            N=N-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends