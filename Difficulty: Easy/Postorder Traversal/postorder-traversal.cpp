/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int> ans;
    vector<int> postOrder(Node* root) {
        // code here
        if(!root)
        return {};
        postOrder(root->left);
        postOrder(root->right);
        ans.push_back(root->data);
        return ans;
    }
};