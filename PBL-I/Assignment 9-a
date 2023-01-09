//============================================================================
// Name        : add.cpp
// Author      : !Ritish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>

using namespace std;

class binary{

public:
	stack<int> s1,s2,s3;

void getData(){
	int n, bit;
	cout << "Enter no of bits";
	cin >> n;

	cout << "Enter bits in number";
	for(int i=0; i<n; i++){
		cin >> bit;
		s1.push(bit);
	}
}

void getData2(){
	int n, bit;
	cout << "Enter no of bits : \n";
	cin >> n;

	cout << "Enter bits in number : \n";
	for(int i=0; i<n; i++){
		cin >> bit;
		s2.push(bit);
	}
}

void addnum(){
	int sum,carry,bit1,bit2;
	sum = carry = bit1 = bit2 = 0;
	while(!s1.empty() || !s2.empty()){
		if(!s1.empty()){
			bit1 = s1.top();
			s1.pop();
		}

		if(!s2.empty()){
			bit2 = s2.top();
			s2.pop();
		}

		sum = (bit1 + bit2 + carry) %2;
		carry = (bit1 + bit2 + carry) / 2;

		s3.push(sum);
	}
}

void display(){

	while (!s3.empty()){
		cout << s3.top() << "\t";
		s3.pop();
	}
}
};

int main() {
	binary obj;

	int choice,conti;

do{
	cout << "Enter Your Choice\n1. Binary Number 1\n2. Binary Number 2\n3. Add Binary\n4. Display\n";
	cin >> choice;

	switch(choice){
	case 1:
		obj.getData();
		break;

	case 2:
		obj.getData2();
		break;

	case 3:
		obj.addnum();
		break;

	case 4:
		obj.display();
		break;



	default:
		cout << "Invalid choice ";
		break;
	}



cout << "Press 1 to continue : ";
cin >> conti;
}
while(conti==1);


	return 0;
}
