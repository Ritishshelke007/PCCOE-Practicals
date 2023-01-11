#include<iostream>
#include<string.h>

using namespace std;

struct Employee{
	int id;
	string name;
	string col;
	int key;
};

class HashTable{
	private:
		Employee Table[10];
	public:
		void insertion();
		void deletion();
		void searching();
		void display();
		int hashfunction(int key);
		
		HashTable();
		~HashTable();
};

void HashTable::searching(){
	int iKey,j,flag=0;
	cout<<"\n**Search Data:"<<"\n";
	cout<<"\nEnter the id to be searched :";
	cin>>iKey;
	
	for(j=0;j<10;j++){
		if(iKey==Table[j].id){
			cout<<"\nEmployee Id Found at index :"<<iKey;
			flag=1;
			goto display;
		}
	}
	if(flag==0){
		cout<<"\nEmployee Id Not Found...";
	}else{
		display:
			cout<<"\nSearched data is :";
			cout<<"\nKey\tId\tName\tCollision"<<"\n";
			cout<<"\n"<<Table[j].key<<"\t"<<Table[j].id<<"\t"<<Table[j].name<<"\t"<<Table[j].col<<"\t";
		
	}

}

int HashTable::hashfunction(int key){
	return key%10;
}
HashTable::HashTable(){
	for(int i=0;i<10;i++){
		Table[i].id=-1;
		Table[i].key=-1;
		Table[i].name="null";
		Table[i].col="null";
	
	}
}

HashTable::~HashTable(){
	cout<<"\nDestroyed..\n";
}
void HashTable::insertion(){
	int id,flag=0;
	int i,choice;
	string name;
	cout<<"\n#Insert Data :"<<"\n";
	
	for(i=0;i<10;i++){
		cout<<"\nInsert Employee "<<i+1<<" Data :"<<"\n";
		cout<<"\nEnter Employee Id : ";
		cin>>id;
		cout<<"\nEnter Employee Name : ";
		cin>>name;
		int index=hashfunction(id);
		int c=index;
		
		while(Table[index].key!=1&&flag!=10){
			index=(index+1)%10;
			flag++;
		}
		if(flag!=0){
			Table[index].col="1";
			
		}
		Table[index].id=id;
		Table[index].name=name;
		Table[index].key=index;
		
		cout<<"\nDo You want to continue (1.Yes | 0.No) :";
		cin>>choice;
		if(choice==0){
			cout<<"\nNumber of Employees are :"<<(i+1);
			break;
		}
	}
}

void HashTable::display(){
	
	cout<<"\nKey\tId\tName\tCollision\t";
	cout<<"\n----------------------------------------------------";
	for(int i=0;i<10;i++){
		cout<<"\n"<<Table[i].key<<"\t"<<Table[i].id<<"\t"<<Table[i].name<<"\t"<<Table[i].col<<"\t";
		cout<<"\n-----------------------------------------------------";
	}
}

void HashTable::deletion(){
	int id,flag=0;
	
	cout<<"\nEnter the id to delete the record :";
	cin>>id;
	
	for(int i=0;i<10;i++){
		if(Table[i].id==id){
			flag=1;
			Table[i].id=-1;
			Table[i].key=-1;
			Table[i].name="null";
			Table[i].col="null";
			cout<<"\Record Deleted....";
		}
	}	
	if(flag==0){
		cout<<"\nEmployee Id Not Found...";
	}
}
int main(){
	HashTable h1;
	int choice,n;
	
	
	do{
		cout<<"\n--------- MENU ----------";
		cout<<"\n1.Insert Data\n2.Search Data\n3.Delete Data\n4.Display Dat\n5.Exit";
		cout<<"\n------------------------";
		cout<<"\nEnter Your Choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:
				h1.insertion();
				break;
			case 2:
				h1.searching();
				break;
			case 3:
				h1.deletion();
				break;
			case 4:
				h1.display();
				break;
			case 5:
				cout<<"\n ||   THANK YOU    ||";
				exit(0);
				break;
			
		}
		cout<<"\nDo You want to continue MAIN MENU Press 1 :";
		cin>>n;
	}while(n==1);
	
	return 0;
}
