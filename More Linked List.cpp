Task-
A Node class is provided for you in the editor. A Node object has an integer data field,data , and a Node instance pointer,next , pointing to another node (i.e.: the next node in a list).
A removeDuplicates function is declared in your editor, which takes a pointer to the head node of a linked list as a parameter. Complete removeDuplicates so that it deletes any duplicate nodes from the list and returns the head of the updated list.
Note: The head pointer may be null, indicating that the list is empty. Be sure to reset your next pointer when performing deletions to avoid breaking the list.

Input Format-
You do not need to read any input from stdin. The following input is handled by the locked stub code and passed to the removeDuplicates function:
The first line contains an integer, N, the number of nodes to be inserted.
The N subsequent lines each contain an integer describing the data value of a node being inserted at the list's tail.

Output Format-
Your removeDuplicates function should return the head of the updated linked list. The locked stub code in your editor will print the returned list to stdout.

Sample Input-
6
1
2
2
3
3
4

Sample Output-
1 2 3 4 


Solution-
include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

          Node* removeDuplicates(Node *head)
          {
            //Write your code here
             if (!head || !head->next) {
            return head;
        }
        
        Node* current = head;
        
        while (current && current->next) {
            if (current->data == current->next->data) {
                // Duplicate node found, skip it
                Node* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory of the duplicate node
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
			
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}
