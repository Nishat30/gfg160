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
     private:
    Node* findKthNode(Node* head, int k)
    {
        Node* temp = head;
        while(temp)
        {
            k--;
            if(temp -> next == NULL){
                return temp;
            }
            temp = temp -> next;

            if(k == 1){
                return temp;
            }
        }

        return NULL;
    }

    Node* reverse(Node* head){
        Node* prevNode = NULL;
        Node* temp = head;

        while(temp){
            Node* nextNode = temp -> next;
            temp -> next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }

        return prevNode;
    }
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
         if(k == 1) return head;
        
        Node* temp = head;
        Node* prevNode = NULL;
    
        while(temp)
        {
            Node* kthNode = findKthNode(temp, k);
            
            Node* nextNode = kthNode -> next;
    
            //to seprate the list
            kthNode -> next = NULL;
    
            reverse(temp);
    
            if(head == temp){
                head = kthNode;
            }
            else{
                prevNode -> next = kthNode;
            }
    
            prevNode = temp;
            temp = nextNode;
        }
    
        return head;
    }
};