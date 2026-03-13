/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int> mp;
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int line=q.front().second;
            q.pop();
            if(mp.find(line)==mp.end()){
                mp[line]=temp->data;
            }
            if(temp->left!=NULL){
                q.push({temp->left,line-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};