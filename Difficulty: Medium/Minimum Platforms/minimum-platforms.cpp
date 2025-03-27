//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        
        // Initialize pointers and counters
        int i = 1;      // Pointer for arrivals (starts at 1 since first train needs a platform)
        int j = 0;      // Pointer for departures
        int curr = 1;    // Current platforms in use (1 for the first train)
        int ans = 1;     // Maximum platforms needed so far
        
        // Traverse through all trains
        while(i < n && j < n){
            // If a new train arrives before the previous one departs
            if(arr[i] <= dep[j]){
                ++curr;  // Need an extra platform
                ++i;     // Move to next arrival
            } else {
                --curr;  // A train departs, free a platform
                ++j;     // Move to next departure
            }
            ans = max(curr, ans);  // Update maximum platforms needed
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends