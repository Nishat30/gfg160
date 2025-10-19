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
    void in(vector<int> &inorder,Node* root){
        if(root==NULL) return;
        in(inorder,root->left);
        inorder.push_back(root->data);
        in(inorder,root->right);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> inorder;
        in(inorder,root);
        int n=inorder.size();
        // [4,8,10,12,14,20,22]
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({abs(inorder[i]-target),inorder[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};