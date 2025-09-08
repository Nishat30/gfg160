/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node*merge(Node*left,Node*right){
      if(!left){
          return right;
      }
      if(!right){
          return left;
      }
      Node*result=NULL;
      if(left->data<=right->data){
          result=left;
          result->next=merge(left->next,right);
      }
      else{
          result=right;
          result->next=merge(left,right->next);
      }
      return result;
    }
    Node*getMiddle(Node*head){
        if(!head){
          return head;
      }
      Node*slow=head;
      Node*fast=head->next;
      while(fast && fast->next){
          fast=fast->next->next;
          slow=slow->next;
      }
      return slow;
    }
    Node* mergeSort(Node* head) {
        // code here
        if(!head || !head->next){
            return head;
        }
        Node*middle=getMiddle(head);
        Node*righthalf=middle->next;
        middle->next=NULL;
        Node*left=mergeSort(head);
        Node*right=mergeSort(righthalf);
        return merge(left,right);
    }
};