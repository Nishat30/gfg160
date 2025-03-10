//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        //longest bitonic= (dp1[i]+dp2[i])-1;
        //i.e the lIS from the front + Lis from thr back - that element coz it is count twice
        
        vector<int>dp1(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp1[prev]>dp1[i]){
                    dp1[i]=1+dp1[prev];
                }
            }
        }
        vector<int>dp2(n,1);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=i+1;prev--){
                if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
        }
        int bitonic=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1&&dp2[i]>1){
            bitonic=max(bitonic,(dp1[i]+dp2[i])-1);}
        }
        return bitonic;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends