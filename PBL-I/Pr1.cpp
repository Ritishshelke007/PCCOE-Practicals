#include<iostream>
#include<conio.h>

using namespace std;

class bank{
    public:
    char name[20];
    float blnc, dep, with;
    int acc;



    bank(){
        cout<<"-----Bank Database------"<<endl;
        cout<<"Enter Name : "<<endl;
        cin>>name;
        cout<<"Account number : "<<endl;
        cin>>acc;
        cout<<"Initial amount : "<<endl;
        cin>>blnc;
    }


    void display(){
        cout<<"Accound Holder : "<<name<<endl;
        cout<<"Account Balance : "<<blnc<<endl;
    }

    void deposit(){
        cout<<"Enter Amount to deposit : "<<endl;
        cin>>dep;
        blnc+=dep;
        cout<<"Amount Deposited Successfully!"<<endl;
    }

    void withdrawal(){
        cout<<"Enter amount to withdraw : "<<endl;
        cin>>with;

        if ((blnc-with)>=0)
        {
            blnc-=with;
           cout<<"Withdrawal success!!"<<endl;
        }
        else{
            cout<<"Insufficient funds!"<<endl;
        }
        
    }

};

int main(int argc, char const *argv[])
{
    bank b1;
    int choice,stop;
    cout<<"Enter Your Choice : "<<endl;
    do
    {
        cout<<"------------------------------------------------"<<endl;
        cout<<"1. Display Balance\n2. Deposit amount\n3. Withdrawal amount"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            b1.display();
            break;


        case 2:
            b1.deposit();
            break;

        case 3:
            b1.withdrawal();
            break;
        
        default:
            cout<<"Invalid choice!"<<endl;
            break;
        }
        cout<<"Press 1 to continue or any other to exit"<<endl;
        cin>>stop;

    } while (stop==1);
    
    return 0;
}

