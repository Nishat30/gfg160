/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int length(Node* head){
        int i=0;
        Node*temp=head;
        while(temp){
            temp=temp->next;
            i++;
        }
        return i;
    }
    Node* swapKth(Node* head, int k) {
        // code here
        Node* temp=head;
        int n=length(head);
        int s=k-1;
        int e=n-k+1;
        Node* start= NULL;
        Node* end=NULL;
        int i=0;
        while (temp) {
            if (i == s) start = temp;
            if (i == e - 1) end = temp; 
            temp = temp->next;
            i++;
        }
        if (start && end) {
            int val = start->data;
            start->data = end->data;
            end->data = val;
        }

        return head;
    }
};