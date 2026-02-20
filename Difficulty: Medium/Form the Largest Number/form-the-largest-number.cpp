class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> s;
        for(int i : arr) {
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        if(s[0] == "0") return "0";
        
        string result = "";
        for(string &str : s) {
            result += str;
        }
        
        return result;
    }
};