//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int>maxi;
        deque<int>mini;
        int ans=0,i=0,j=0,ii,jj;
        while(j<arr.size()){
            while(!mini.empty() && arr[mini.back()]>arr[j]) mini.pop_back();
            while(!maxi.empty() && arr[maxi.back()]<arr[j]) maxi.pop_back();
            mini.push_back(j);
            maxi.push_back(j);
            while(arr[maxi.front()]-arr[mini.front()]>x && i<j){
                if(i==mini.front()) mini.pop_front();
                if(i==maxi.front()) maxi.pop_front();
                i++;
            }
            if(j-i+1>ans){
                ans=j-i+1;
                ii=i;
                jj=j;
            }
            j++;
        }
        vector<int>ans1;
        for(int k=ii;k<=jj;k++) ans1.push_back(arr[k]);
        return ans1;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends