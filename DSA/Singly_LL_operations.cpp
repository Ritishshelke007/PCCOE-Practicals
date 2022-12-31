#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data=value;
        next=NULL;
    }
};

void insertAtEnd(node* &head, int val){
    node* temp = NULL;
    temp=head;
    node* newNode = new node(val);

    if (head==NULL)
    {
        head=newNode;
        return;
    }

    while (temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    temp->next=newNode; 
}

// insert at head

void insertAtHead(node* &head, int val){
    node* newNode = new node(val);

    if (head==NULL)
    {
       head=newNode;
       return;
    }

    newNode->next=head;
    head=newNode;
}


void display(node* head){
    node* temp = head;

    if (head==NULL)
    {
       cout << "List is empty"<<endl;
       return;
    }

    cout << "------ Displaying Linked list -------"<<endl;
    while (temp!=NULL)
    {
        cout << temp->data << "--->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
    
    
}

//insert at position

void insertAtPos(node* &head, int pos,int val){
    node* temp=head;
    node* newNode = new node(val);

for(int i=2; i < pos; i++) {
  if(temp->next != NULL) {
    temp = temp->next;
  }
}

newNode->next = temp->next;
temp->next = newNode;
}

//searching
bool search(node* head, int val){
node* temp=head;

    if (head==NULL)
    {
        cout << "list is empty!!";
        return false;
    }

    while (temp!=NULL)
    {
        if (temp->data==val)
        {
            return true;
        }
        temp=temp->next; 
    }

    return false;  
}

void deleteAtBegin(node* &head){
    node* temp = head;
    head = head->next;

    free(temp);
    cout << "Deleted First node \n";
}

void deleteAtEnd(node* &head){
    node* temp = head;
    node* todel = NULL;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next->next=todel;
    temp->next=NULL;
    free(todel);
}

// delete given data 

void delAtGiven(node* &head,int val){
    node* temp = head;
    node* todel = NULL;
        if (temp->data==val)
        {
            deleteAtBegin(head);
        }
        else{
            while (temp->next->data!=val)
            {
                temp=temp->next;
            }
            todel = temp->next;
            temp->next=temp->next->next;   
        }
        
}

int main(){
    int choice,conti,pos;
    node* head = NULL;

do
{
    cout << "---------------------------------\n";
    cout << "Enter Your Choice : \n1. Insert At End\n2. Insert At Head\n3. Insert At Position\n4. Display\n5. Search\n6. Delete At Beginning\n7. Delete At End\n8. Delete given data\n";
    cout << "---------------------------------\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        int no,val;
        bool found;
        cout << "Enter node data : ";
        cin >> val;
        cout << endl;
        insertAtEnd(head,val);
        break;

    case 2:
        cout << "Enter data to add at head : ";
        cin >> val;
        insertAtHead(head,val);
        break;


    case 3:
        cout << "Enter position to add : ";
        cin >> pos;
        cout << "\nEnter data to add : ";
        cin >> val;
        insertAtPos(head,pos,val);
        break;

    case 4:
        display(head);
        break;
    
    case 5:
        cout << "Enter data to search in list : ";
        cin >> val;
        found = search(head,val);

        if (found)
        {
            cout << "Present in list" <<endl;
        }
        else{
            cout << "not found"<<endl;
        }
        
        break;

    case 6:
        deleteAtBegin(head);
        break;

    case 7:
        deleteAtEnd(head);
        break;

    case 8:
        cout << "Enter Data to delete : ";
        cin >> val;

        delAtGiven(head,val);
        break;


    default:
        cout << "invalid choice\n";
        break;
    }
    cout << "Press 1 to continue : ";
    cin >> conti;
} while (conti==1);

    return 0;
}
