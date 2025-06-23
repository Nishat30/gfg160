class Solution {
    string addString(string &s1, string &s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0)
            sum += (s1[i] - '0');

        if (j >= 0)
            sum += (s2[j] - '0');

        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i--;
        j--;
    }
    while (!res.empty() && res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());

    return res;
    }
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        string s1 = "", s2 = "";

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0)
              s1.push_back(arr[i] + '0');
            else
              s2.push_back(arr[i] + '0');
        }
        return addString(s1, s2);
    }
};