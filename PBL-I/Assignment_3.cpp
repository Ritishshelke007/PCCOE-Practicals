#include <iostream>
using namespace std;

class vehicle
{
	private:
		float mileage;
		long int price;
		
	public :
		void get_veh()
		{
			cout << "\nEnter the mileage of vehicle : ";
			cin >> mileage;
			
			cout << "\nEnter the price of the vehicle : ";
			cin >> price;
		}
		
		void display_veh()
		{
			cout << "\n\n DISPLAYING DETAILS -------->" ;
			cout << "\n\nMileage :" << mileage << "\n" << "Price :" << price << "\n";
		}
};

class car : public vehicle
{
	public :
		int own_cost , warrenty , sit_capacity ;
		char fuel[10];
		
		void get_car()
		{
			cout << "\nEnter the ownership cost : ";
			cin >> own_cost;
			
			cout << "\nEnter the number of years warrenty : ";
			cin >> warrenty;
			
			cout << "\nEnter the sitting capacity : ";
			cin >> sit_capacity;
			
			cout << "\nEnter the type of fuel  (Disel or Petrol) : ";
			cin >> fuel;
		}	
		
		void display_car()
	{
		cout << "Ownership cost :" << own_cost << "\n" << "Warrenty :" << warrenty << "\n" ;
		cout << "Sitting capacity :" << sit_capacity << "\n" << "Fuel :" << fuel << "\n" ;
	}
		
};

class bike : public vehicle
{
	public :
		int cylinder ,gear ,fuel_tank;
		char cooling[15];
		char wheel[10];
		
		void get_bike()
		{
			cout << "\nEnter number of cylinder : ";
			cin >> cylinder;
			
			cout << "\nEnter number of gears : ";
			cin >> gear;
			
			cout << "\nEnter the cooling type (air,liquid,oil) : ";
			cin >> cooling;
			
			cout << "\nEnter the type of wheel (spokes,alloy) : ";
			cin >> wheel;
			
			cout << "\nEnter the size of fuel tank (inches) : ";
			cin >> fuel_tank;	
		}
		
		void display_bike()
		{
			cout << "Number of cylinder :" << cylinder << "\n" << "Number of gears :" << gear << "\n" ;
			cout << "Cooling type :" << cooling << "\n" << "Type of wheel :" << wheel << "\n" << "Fuel tank size :" << fuel_tank << "\n";	
		}
		
};

class audi : public car
{
	public :
		char num[15];
		
		void get_audi()
		{
			cout << "\nEnter model number : ";
			cin >> num;
		}
		
		void display_audi()
		{
			cout << "Model number :" << num;
		}
};

class ford : public car
{
	public :
		char num[15];
		
		void get_ford()
		{
			cout << "\nEnter model number : ";
			cin >> num;
		}
		
		void display_ford()
		{
			cout << "Model number :" << num;
		}
};

class bajaj : public bike
{
	public :
		char num[15];
		
		void get_bajaj()
		{
			cout << "\nEnter model number : ";
			cin >> num;
		}
		
		void display_bajaj()
		{
			cout << "Model number :" << num;
		}
};

class TVS : public bike
{
	public :
		char num[15];
		
		void get_TVS()
		{
			cout << "\nEnter model number : ";
			cin >> num;
		}
		
		void display_TVS()
		{
			cout << "Model number :" << num;
		}
};


int main()
{
	audi A;
	ford F;
	bajaj B;
	TVS T;
	
	int ch;
	
	do
	{
		cout << "\n\nPlease select\n" ;
		cout << "\n" << "1.About AUDI CAR " << "\n" << "2.About FORD CAR " << "\n" << "3.About BAJAJ BIKE" << "\n" << "4.About TVS BIKE" << "\n" << "5.Exit !" << "\n";
		cout << "\nEnter your choice : " ;
		cin >> ch ;
		
		switch(ch)
		{
			case 1:
				A.get_veh();
				A.get_car();
				A.get_audi();
				A.display_veh();
				A.display_car();
				A.display_audi();
				break ;
				
			case 2:
				F.get_veh();
				F.get_car();
				F.get_ford();
				F.display_veh();
				F.display_car();
				F.display_ford();
				break ;	
				
			case 3:
			    B.get_veh();
				B.get_bike();
				B.get_bajaj();
				B.display_veh();
				B.display_bike();
				B.display_bajaj();
				break ;
				
			case 4:
				T.get_veh();
				T.get_bike();
				T.get_TVS();
				T.display_veh();
				T.display_bike();
				T.display_TVS();
				break ;	
				
			case 5:
				cout << "\nEXIT !" ;
				break ;
				
			default :
				cout << "\nInvalid !Check your choice again " ;	
				break ;	
		}
	}while(ch!=5);
	
	return 0;
}

