#include<conio.h>
#include<iostream>
using namespace std;


class complex{
private:
float x,y;

public:

complex(){
    x=0;
    y=0;
}

friend istream &operator>>(istream &input, complex &t){
    cout << "Enter real part : ";
    input >> t.x;
    cout << "Enter imaginary part : ";
    input >> t.y;
}

friend ostream &operator<<(ostream &output, complex &t){
    output << t.x << "+" <<t.y << "i";
}

complex operator+(complex);
complex operator-(complex);
complex operator*(complex);

};

complex complex :: operator+(complex c){
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

complex complex :: operator-(complex c){
    complex temp2;
    temp2.x = x - c.x;
    temp2.y = y - c.y;
    return temp2;
}

complex complex :: operator*(complex c){
    complex temp1;
    temp1.x = (x*c.x) - (y*c.y);
    temp1.y = (y*c.x) + (x*c.y);
    return temp1;
}





int main(){
    complex c1,c2,c3,c4,c5;

    cout << "Default constructor : "<<endl;
    cout << c1 << endl;

    cout << "Enter no 1 : "<<endl;
    cin >> c1;

    cout << "Enter no 2 : "<<endl;
    cin >> c2;

    c3 = c1+c2;
    c4 = c1-c2;
    c5 = c1*c2;


    cout << "-----------Result------------\n";
    cout << "Addition of complex no : " << c3 << endl;
    cout << "Subtraction of complex no : " << c4 << endl;
    cout << "Multiplication of complex no : " << c5 << endl;
    



    return 0;
}

