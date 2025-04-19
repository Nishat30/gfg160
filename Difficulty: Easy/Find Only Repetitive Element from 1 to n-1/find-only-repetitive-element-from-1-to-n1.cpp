//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
struct Trie {
    Trie* links[2]; // since we're dealing with binary bits (0 and 1)
    bool isEnd = false;

    Trie() {
        links[0] = nullptr;
        links[1] = nullptr;
    }
};
class Solution {
  public:
    Trie* root = new Trie();

    bool insert(int num) {
        Trie* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->links[bit]) {
                node->links[bit] = new Trie();
            }
            node = node->links[bit];
        }

        if (node->isEnd) {
            // number already inserted → duplicate
            return true;
        } else {
            node->isEnd = true;
            return false;
        }
    }
    int findDuplicate(vector<int>& arr) {
        // code here
        for (int num : arr) {
            if (insert(num)) {
                return num;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends