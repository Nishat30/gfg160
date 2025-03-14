//{ Driver Code Starts
//Initial Template for C++

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// User function Template for C++
class Solution {
  public:
    long double NthTerm(int N){
        long double  p;
        if(N%2 == 1)
           p = pow(2, N/2);
        else
           p = pow(3, N/2 - 1);
        return pow(2, p);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout<< fixed << setprecision(0)<<ob.NthTerm(N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends