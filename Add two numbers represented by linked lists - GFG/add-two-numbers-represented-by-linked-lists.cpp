//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
     private:
        Node* reverse(Node* head){
            Node* prev=NULL,*curr=head,*next=head;
            
            while(curr){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        l1=reverse(l1);
        l2=reverse(l2);
        Node* L1=l1;
        Node * L2=l2;
        Node* start=new Node(-1);
        Node* startHead=start;
        int carry=0;
        while(l1 && l2){
            int x=l1->data+l2->data+carry;
            int n=x%10;
            start->next=new Node(n);
            carry=x/10;
            start=start->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                int x=l1->data+carry;
                int n=x%10;
                start->next=new Node(n);
                carry=x/10;
                start=start->next;
                l1=l1->next;
            }
        }
        if(l2){
            while(l2){
                int x=l2->data+carry;
                int n=x%10;
                start->next=new Node(n);
                carry=x/10;
                start=start->next;
                l2=l2->next;
            }
        }
        if(carry){
            start->next=new Node(carry);
        }
        startHead=reverse(startHead->next);
        return startHead;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends