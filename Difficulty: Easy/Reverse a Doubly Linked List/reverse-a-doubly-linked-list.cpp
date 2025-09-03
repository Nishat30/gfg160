/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* ansHead = NULL;
        
        while(curr != NULL){
            ansHead = curr;
            Node* nodeNext = curr->next;
            Node* nodePrev = curr->prev;
            
            curr->next = nodePrev;
            curr->prev = nodeNext;
            
            curr = nodeNext;
        }
        
        return ansHead;
    }
};