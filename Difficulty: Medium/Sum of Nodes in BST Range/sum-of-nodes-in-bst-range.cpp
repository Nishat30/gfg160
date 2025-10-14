/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(root==NULL) return 0;
        
        int sum=0;
        
        if(root->data>=l && root->data<=r){
            sum+=root->data;
        }
        if(root->data>l){
            sum+=nodeSum(root->left,l,r);
        }
        if(root->data<r){
            sum+=nodeSum(root->right,l,r);
        }
        return sum;
    }
};
