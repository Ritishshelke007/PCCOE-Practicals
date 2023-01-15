#include <iostream>
using namespace std;

class Shape{
public:
    double len,bre;
    Shape(){
        len = 0;
        bre = 0;
    }

    void getData(){
        cout << "Enter Side 1 : ";
        cin >> len;
        cout << "Enter Side 2 : ";
        cin >> bre;
    }

    virtual void display_area() = 0;
};

class Triangle : public Shape{
    private:
    double area;

public:
    void display_area(){
        area = 0.5*len*bre;
        cout << "Area of Triangle is : " << area << endl;;
    }

};

class Rectangle : public Shape{
public:
    double area;

    void display_area(){
        area = len*bre;
        cout << "Area of Rectangle is : "<<area << endl;
    }

};


int main(){
    Shape *p;
    Rectangle r;
    Triangle t;
    int choice,c;

do
{

    cout << "------------------------\n";
    cout << "Choice\n1. Compute area of rectangle\n2. Compute area of Triangle\n";
    cout << "------------------------\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        p = &r;
        p->getData();
        p->display_area();
        
        break;

    case 2:
        p = &t;
        p->getData();
        p->display_area();
        break;

    
    default:
        cout << "Invalid choice!";
        break;
    }
cout << "Press 1 to continue : ";
cin >> c;
} while (c==1);
    return 0;
}
