//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topNode;
        queue<pair<Node*,int> >q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* top=temp.first;
            int hd=temp.second;
            topNode[hd]=top->data;
            if(top->left){
                q.push(make_pair(top->left,hd-1));
            }
            if(top->right){
                q.push(make_pair(top->right,hd+1));
            }
        }
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};
