#include <bits/stdc++.h> 
#include <inttypes.h>  
using namespace std; 
  
 
class Node  
{  
    public: 
    int data;  
    Node* npx; 
};  

Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
  

void insert_first(Node **head_ref, int data)  
{  
      
    Node *new_node = new Node();  
    new_node->data = data;  
  
    
    new_node->npx = *head_ref;  

    if (*head_ref != NULL)  
    {  
  
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);  
    }  
  
   
    *head_ref = new_node;  
}  

void insert_end(Node **head_ref, int data){
    Node *new_node = new Node();  
    new_node->data = data;
    Node *prev = NULL, *curr = *head_ref, *next;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(curr != NULL){
        next = XOR (prev, curr->npx);
        prev = curr;  
        curr = next;
    }
    new_node->npx = XOR(prev, NULL);
    prev->npx = XOR(new_node, XOR(prev->npx, NULL));
    prev = new_node;
}
  

void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
  
    cout << "Following are the nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {  
          
        cout<<curr->data<<" ";  

        next = XOR (prev, curr->npx);   
        prev = curr;  
        curr = next;  
    }  
    cout<<"\n";
}  
  
int main ()  
{   int ch, ele;
    
    Node *head = NULL;  
    while(true){
        cout<<"1: Insert element at the beginning\n2: Insert at the end\n3: Print the elements in the link list\n4: Exit"<<endl;
        cin>>ch;
        if(ch == 1){
            cout<<"Enter the element"<<endl;
            cin>>ele;
            insert_first(&head, ele);
        }
        if(ch ==2){
            cout<<"Enter the element"<<endl;
            cin>>ele;
            insert_end(&head, ele);
        }
        if(ch == 3){
            printList(head);
        }
        if(ch == 4){
            break;
        }
    }

 
  
    return (0);  
}  

