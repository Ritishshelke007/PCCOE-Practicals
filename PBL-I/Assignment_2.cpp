#include <iostream>
#define max 30  
using namespace std;


class Student
{ 
   	private:
     	int roll_no;
     	string name, address, Class, dob, blood_gp,div;
     	long int phone_no; 
    public:
     	static int count; 
     	void setdata(int i);
     	void getdata(int i);
     	inline static void display_count();
      	Student();
      	~Student();
};


void Student :: setdata(int i)
{
    cout<<"\nEnter data of student-"<<(i+1)<< " : "<<endl;

    cin.ignore(); 
    cout<<"Enter name: ";
    getline(cin,name); 
    
    cout<<"Enter address: ";
    getline(cin,address); 

    cout<<"Enter class: ";
    getline(cin,Class);

    cout<<"Enter division: ";
    getline(cin,div);

    cout<<"Enter D.O.B: ";
    getline(cin,dob);

    cout<<"Enter blood group: ";
    getline(cin,blood_gp);

    cout<<"Enter Roll No: ";
    cin>>roll_no;

    cout<<"Enter phone no: ";
    cin>>phone_no;
      
    count++; 
}


void Student :: getdata(int i)
{
    cout<<"\nStudent-" <<(i+1)<< " Data: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Class: "<<Class<<endl;
    cout<<"Division: "<<div<<endl;
    cout<<"D.O.B: "<<dob<<endl;
    cout<<"Blood Group: "<<blood_gp<<endl;
    cout<<"Roll No: "<<roll_no<<endl;
    cout<<"Phone No: "<<phone_no<<endl;
}

Student :: Student()
{
    cout<<"Constructor.."<<endl;
    name = "null";
    address = "null";
    Class = "null";
    div = "null" ;
    dob = "null";
    blood_gp = "null";
    roll_no = 0;
    phone_no = 0; 
}


Student :: ~Student()
{
    cout<<"Destroyed.."<<endl;
}

void Student :: display_count()
{
     cout<<"\nThe count of students is: "<<count<<endl;
}

int Student :: count=0;

int main()
{  
    cout<<"\n # Student Database System # \n"<<endl;
    int i,n,ch;

    cout<<"Enter number of students: ";
    cin>>n;

    Student stud[n]; 
   
    do
	{
    	cout<<"\n#Menu: \n1.Setdata \n2.Getdata \n0.Exit \nEnter your choice:  ";
    	cin>>ch;

    	switch(ch)
		{
		case 1:
            for(i=0;i<n;i++)
            {
                stud[i].setdata(i);
            }
            break;

        case 2: 
            for(i=0;i<n;i++)
            {
                stud[i].getdata(i);
            }
            break;

        case 0:  
            goto end;  
            break;

        default: 
            cout<<"Enter correct choice!"<<endl;
            break; 

    }
 } while(1); 
   end: 
   Student :: display_count();
   return 0;
}

