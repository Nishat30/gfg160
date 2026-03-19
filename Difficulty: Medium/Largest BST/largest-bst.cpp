/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    info solve(Node* root,int &ans){
        if(root==NULL){
            return {INT_MIN,INT_MAX,true,0};
        }
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        info currNode;
        currNode.size=left.size+right.size+1;
        currNode.maxi=max(root->data,right.maxi);
        currNode.mini=min(root->data,left.mini);
        if(left.isBST && right.isBST && (root->data<right.mini && root->data>left.maxi)){
            currNode.isBST=true;
        }else{
            currNode.isBST=false;
        }
        if(currNode.isBST){
            ans=max(ans,currNode.size);
        }
        return currNode;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxSize=0;
    	info temp=solve(root,maxSize);
    	return maxSize;
    }
};
