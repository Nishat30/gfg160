/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve(int preS, int postS, int preE, vector<int>&pre, vector<int>&post){
        if(preS>preE) return NULL;
        
        Node* root=new Node(pre[preS]);
        if(preS==preE){
            return root;
        }
        
        int j=postS;
        
        while(post[j]!=pre[preS+1]){
            j++;
        }
        int num=j-postS+1;
        root->left=solve(preS+1, postS, preS+num, pre, post);
        root->right=solve(preS+num+1, j+1, preE, pre, post);
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        return solve(0, 0, pre.size()-1, pre, post);
    }
};