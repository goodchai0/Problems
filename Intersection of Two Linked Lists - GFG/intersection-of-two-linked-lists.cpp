//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* headB, Node* headA)
    {
        // code here
        // return the head of intersection list
        Node *ptr1 = headA;
		Node *ptr2 = headB;
		Node* start=new Node(-1);
		Node* startHead=start;
		unordered_map<int,int>mp;

		while(ptr1 != NULL){
			mp[ptr1->data]++;
			ptr1=ptr1->next;
		}
		while(ptr2!=NULL){
		    if(mp[ptr2->data]>0){
		        start->next=ptr2;
		        start=start->next;
		    }
		    ptr2=ptr2->next;
		}
		start->next=NULL;
		return startHead->next;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends