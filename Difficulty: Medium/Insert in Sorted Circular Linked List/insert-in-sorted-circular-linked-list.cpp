/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp=head;
         Node* t=new Node(data);
         
         if(head==NULL){
             
             
             t->next=t;
             
             return t;
         }
         
         if(data <= head->data){
             while(temp->next!=head){
                 temp=temp->next;
             }
             temp->next=t;
             t->next=head;
             return t;
             
         }
         
        if(head->next == head){
           
            head->next=t;
            t->next=head;
            return head;
        }
        
        while(temp->next !=head && temp->next->data < data){
           
            temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;
        
      return head;
    }
};