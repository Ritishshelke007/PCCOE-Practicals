#include <iostream>
using namespace std;

struct stack{
    int data;
    stack* next;
} *top=NULL;

void push(int data){
    stack* newNode = new stack;
    newNode->data=data;
    newNode->next=NULL;

    if (newNode==NULL)
    {
        cout << "Stack overflow";
        return;
    }

    newNode->next = top;
    top = newNode;
}

void print(){
    stack* temp;
    temp = top;

    cout << "-------------------------" << endl;
    while (temp)
    {
       cout << temp->data << "\t";
       temp= temp->next;
    }
    cout << "\n-------------------------" << endl;

    
}


void pop(){
    stack* temp = top;

    if (top==NULL)
    {
        cout << "Stack underflow!"<<endl;
        return;
    } 
    

    top = top->next;
    free(temp);
    cout << "Top popped!!" << endl;
}


void peek(){
    cout << "Top element : ";

    if (top==NULL)
    {
        cout << "Stack underflow!"<<endl;
        return;
    }

    cout << top->data << endl;
}


int main(){

    int choice,c,data;
do
{

    cout << "Enter Your choice : \n1. Push\n2. Pop\n3. Peek\n4. Display\n";
    cout << "----------------------\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter data : ";
        cin >> data;
        push(data);
        break;

    case 2:
        pop();
        break;


    case 3:
        peek();
        break;


    case 4:
        print();
        break;
    
    default:
        break;
    }


    cout << "Continue ? 1|Yes 0|No : ";
    cin >> c;
} while (c==1);

    return 0;
}
