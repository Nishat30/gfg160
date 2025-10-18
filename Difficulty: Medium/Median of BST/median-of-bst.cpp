/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void in(Node*root, vector<int>& ans){
        if(root==NULL) return;
        in(root->left,ans);
        ans.push_back(root->data);
        in(root->right,ans);
    }
    int findMedian(Node* root) {
        // Code here
        vector<int> ans;
        in(root,ans);
        int n=ans.size();
        if(n%2==0){
            return ans[(n/2)-1];
        }
        return ans[((n+1)/2)-1];
    }
};