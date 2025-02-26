//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
         int n=arr.size();
        
       vector<int> res(n,0);
       stack<int> st;
       
       vector<int> left(n),right(n); // keep track of index of prev and next samller  element respectively
       
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
           
           if(st.empty()) left[i]=-1;
           else left[i]=st.top();
           
           st.push(i);
       }
       
       while(!st.empty()) st.pop();
       
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
           
           if(st.empty()) right[i]=n;
           else right[i]=st.top();
           
           st.push(i);
       }
       
       //get maxWindow for each element in arr
       for(int i=0;i<n;i++){
           
           int maxWindow = right[i] - left[i] -1;
           res[maxWindow-1] = max(res[maxWindow-1],arr[i]);
       }
       
       //fill all empty ones
       for(int i=n-2;i>=0;i--){
          res[i] = max(res[i],res[i+1]);
       }
       
       return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends