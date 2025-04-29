//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

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



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends