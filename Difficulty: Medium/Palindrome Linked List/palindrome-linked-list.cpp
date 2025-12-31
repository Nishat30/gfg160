/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        Node* slow=head;
        Node*  fast=head;
        Node* temp=head;

        int size=0;

        while(temp){
            temp=temp->next;
            size++;
        }
        while(fast && fast->next){
    
    slow=slow->next;
    
    fast=fast->next->next;
}


Node* prev=nullptr;

Node* curr=slow;


while(curr){
    
   Node* next=curr->next;
    curr->next=prev;
    prev=curr;
    
    curr=next;
}
slow=prev;


while(slow){
    
    if(slow->data!=head->data){
        
       return false;
    }
    else{
     slow=slow->next;
        
        head=head->next;
        
    }
}

return true;
    }
};

