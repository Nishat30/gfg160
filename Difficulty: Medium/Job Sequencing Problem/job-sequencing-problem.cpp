//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool static comp(pair<int,int> job1,pair<int,int> job2){
        return (job1.second>job2.second);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>> job;
        int max_dead=0;
        for(int i=0;i<n;i++){
            job.push_back({deadline[i],profit[i]});
            max_dead=max(max_dead,deadline[i]);
        }
        sort(job.begin(),job.end(),comp);
        vector<int> slot(max_dead+1,-1);
        int countJobs = 0, jobProfit = 0;
        for(int i=0;i<n;i++){
            for (int j = job[i].first; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += job[i].second;
               break;
            }
         }
        }
        return {countJobs,jobProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends