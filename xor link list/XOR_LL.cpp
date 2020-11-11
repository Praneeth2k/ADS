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

void delete_end(Node **head){
    Node *prev = NULL, *curr, *next;
    curr = *head;
    if(*head == NULL){
        cout<<"Nothing to delete"<<endl;
        return;
    }
    if((*head)->npx == NULL){
        cout<<"Deleted "<<(*head)->data<<endl;
        *head = NULL;
        return;
    }
    while(XOR(curr->npx, prev) != NULL){
        next = XOR (prev, curr->npx);
        prev = curr;  
        curr = next;
    }
    prev->npx = XOR(NULL, XOR(prev->npx, curr));
    return;
}

void deleteFirst(Node **head_ref){
    if(*head_ref == NULL){
        cout<<"Nothing to delete\n";
        return;
    }
    if((*head_ref)->npx == NULL){
        cout<<"Deleted "<<(*head_ref)->data<<endl;
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    cout<<"Deleted "<<(*head_ref)->data<<endl;
    Node *prev = *head_ref;
    *head_ref = (*head_ref)->npx;
    (*head_ref)->npx = XOR(NULL, (XOR(prev, (*head_ref)->npx)));
    free(prev);

}

void delete_ele(Node **head, int ele){
    Node *prev = NULL, *curr, *next;
    curr = *head;
    if(*head == NULL){
        cout<<"Nothing to delete"<<endl;
        return;
    }
    if((*head)->data == ele){
        deleteFirst(head);
        return;
    }
    while(XOR(curr->npx, prev) != NULL){
        if(curr->data == ele){
            Node *temp = prev;
            prev->npx = XOR(XOR(prev->npx,curr), XOR(curr->npx, prev));
            next = XOR (temp, curr->npx);
            next->npx = XOR(XOR(next->npx, curr), temp);
            return;
        }
        next = XOR (prev, curr->npx);
        prev = curr;  
        curr = next;
    }
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
        cout<<"1: Insert element at the beginning\n2: Insert at the end\n3: Print the elements in the link list\n4: Delete first\n5: Delete end\n6: Exit"<<endl;
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
            deleteFirst(&head);
        }
        if(ch == 5){
            delete_end(&head);
        }
        if(ch == 6){
            cout<<"Enter the element to delete\n";
            cin>>ele;
            delete_ele(&head, ele);
        }
        if(ch == 7){
            break;
        }
    }

 
  
    return (0);  
}  

