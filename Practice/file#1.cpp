#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int count,id,i;
    string name, dep, line;
    float salary;
    
    cout<<"--Employee Database--"<<endl;
    ofstream fout("Employee.txt");
    
    cout << "Total No of Employee : "<<endl;
    cin >> count;
    
    fout << "id" <<"\t" << "name" <<"\t" <<"dep" << "\t" << "salary" <<"\t" << "\n";

    for(i=1;i<=count;i++){
        cout << "Enter Data of Employee no "<<i<<":"<<endl;
        cout << "Enter Id  ";
        cin >> id;
        
        cout << "Enter Name : ";
        cin >> name;
        
        cout << "Enter Department : ";
        cin >> dep;
        
        cout << "Enter Salery : ";
        cin >> salary;
        
        fout << id <<"\t" << name <<"\t" <<dep << "\t" << salary <<"\t" << "\n";
        
    }
    
    fout.close();
    
    
    ifstream fin;
    fin.open("Employee.txt");
    
    cout<<"----Display Data----"<<endl;
 
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
    return 0;
}
