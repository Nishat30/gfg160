/*Linked list Node structure

struct Node
{
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
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* head = new Node(0);
        Node* ptr = head;
        Node* curr = NULL;
        while(1){
            int pos  = -1;
            for(int i=0;i<arr.size();i++){
                if(curr==NULL && arr[i]){
                    curr = arr[i];
                    pos = i;
                }
                else if(curr && arr[i]){
                    if(curr->data>arr[i]->data){
                        curr = arr[i];
                        pos = i;
                    }
                }
            }
            if(pos == -1 && curr == NULL)break;
            if(curr){
                ptr->next = curr;
                ptr = ptr->next;
                arr[pos] = arr[pos]->next;
                curr = NULL;
            }
        }
        return head->next;
    }
};

