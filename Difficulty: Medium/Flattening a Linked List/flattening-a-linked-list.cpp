/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        priority_queue<pair<int, Node*> , vector<pair<int, Node*>> , greater<pair<int, Node*>>> pq;
        Node* temp= root;
        while(temp){
            pq.push(make_pair(temp->data, temp));
            temp= temp->next;
        }
        Node* dummy= new Node(-1);
        Node* tail= dummy;
        while(!pq.empty()){
            pair<int, Node*> temp= pq.top();
            pq.pop();
            Node* node= temp.second;
            tail->bottom= node;
            if(temp.second->bottom){
                pq.push(make_pair(temp.second->bottom->data, temp.second->bottom));
                
            }
            tail= node;
        }
        return dummy->bottom;
    }
};