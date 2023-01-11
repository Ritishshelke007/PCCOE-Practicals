#include<iostream>
using namespace std;


struct node{
    int data;
    node* next;
};

struct node* front;
struct node* rear;

void enqueue(int data){
    node* newNode = new node;

    newNode->data=data;
    newNode->next=NULL;

    if (front==NULL)
    {
        front = newNode;
        rear = newNode;

        front->next = NULL;
        rear->next = NULL;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    

}

void print(){
    node* temp = front;

    if (front==NULL)
    {
        cout << "list empty" << endl;
        return;
    }
    while (temp!=NULL)
    {
       cout << temp->data << "\t";
       temp = temp->next;
    }
    cout << endl;

}

void dequeue(){
    struct node* temp = front;

    if (front == NULL)
    {
        cout << "underflow"<<endl;
        return;
    }
    front = front->next;
    free(temp);
    cout << "Deque Successfull!" <<endl;
}


int main(){


    int choice,c,data;

    do
    {
        cout << "Enter your choice : \n1. enqueue\n2. dequeue\n3. display\n";
        cout<<"---------------------------\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            enqueue(data);
            break;


        case 2:
            dequeue();
            break;

        case 3:
            print();
            break;
        
        default:
            break;
        }






        cout << "Continue ? 1|Yes 2|No : ";
        cin >>c;
    } while (c==1);
    

    return 0;
}
