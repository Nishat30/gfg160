class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> meetings;
        int n=start.size();
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        int cnt=1;
        int check=meetings[0].first;
        for(int i=1;i<n;i++){
            if(meetings[i].second>check){
                check=meetings[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};