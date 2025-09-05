
/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead = new Node(-1);  // Dummy head for 0s
        Node* oneHead = new Node(-1);   // Dummy head for 1s
        Node* twoHead = new Node(-1);   // Dummy head for 2s
        
        // Pointers to traverse and build the three lists
        Node* zeroPtr = zeroHead;
        Node* onePtr = oneHead;
        Node* twoPtr = twoHead;
        
        Node* ptr = head;  // Pointer to traverse the original list
        
        while (ptr != nullptr) {
            if (ptr->data == 0) {
                // Append to 0s list
                zeroPtr->next = ptr;
                zeroPtr = zeroPtr->next;
            } else if (ptr->data == 1) {
                // Append to 1s list
                onePtr->next = ptr;
                onePtr = onePtr->next;
            } else {
                // Append to 2s list
                twoPtr->next = ptr;
                twoPtr = twoPtr->next;
            }
            ptr = ptr->next;  // Move to the next node
        }
        // Terminate the 2s list
        twoPtr->next = nullptr;
        
        // Connect 1s list to 2s list
        onePtr->next = twoHead->next;
        
        // Connect 0s list to 1s list
        zeroPtr->next = oneHead->next;
        
        // The new head is the first node after the dummy 0s head
        return zeroHead->next;
    }
};


