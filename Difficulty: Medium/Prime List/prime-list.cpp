//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  private:
    unordered_map<int,bool>primes;
    int isPrime(int num){
        if(primes.find(num) != primes.end()){
            primes[num];
        }
        if(num<=1){
            primes[num] = false;
            return false;
        }
        else if (num<=3){
            primes[num] = true;
            return true;
        }
        else{
            for(int i=2;i<=sqrt(num);i++)
            {
                if(num%i == 0)
                {
                    primes[num] = false;
                    return false;
                }
            }
            primes[num] = true;
            return true;
        }
    }
    int NearestPrime(int num)
    {
        if(isPrime(num))
        {
            return num;
        }
        int l = num--;
        int h = num++;
        while(true)
        {
            if(l>=2 && isPrime(l))
            {
                return l;
            }
            if(isPrime(h))
            {
                return h;
            }
            l--;
            h++;
        }
    }
  public:
    Node *primeList(Node *head) {
        // code here
        Node* temp = head;
        while(temp)
        {
            temp->val = NearestPrime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends