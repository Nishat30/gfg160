// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; 
        vector<int> ans;
        for (int i = 0; i < notes.size(); i++) {
            while (N >= notes[i]) {
                ans.push_back(notes[i]);
                N -= notes[i];
            }
        }
        return ans;
    }
};