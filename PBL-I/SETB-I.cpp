#include <iostream>

using namespace std;

class sets{
    int cust;
    string name[20];
    
    public:
    
    void add_cust(){
    cout<<"Enter number of customers : ";
    cin >> cust;       

    for(int i = 0; i<cust ; i++){
        cout << "Enter customer no " <<i<< " : ";
        cin >> name[i];
    }
        
    }
    
    void display(){
        cout << "Display elements of set \n";
        for( int i = 0 ; i<cust ; i++){
            cout << name[i] << "\t";
        }
        
    }
    
    sets ABUnion(sets setB){
        sets temp;
        int k = 0, count[setB.cust]={0};
        
        
        for(int i = 0; i< cust; i++){
            temp.name[i]=name[i];
            k++;
        }
        
        for(int i = 0; i < cust; i++){
            for(int j = 0; j < setB.cust ; j++){
                if(temp.name[i]==setB.name[j]){
                    count[j]++;
                    
                }
            }
        }
        
        for(int i = 0; i<setB.cust; i++){
            if(count[i]==0){
                temp.name[k]=setB.name[i];
                k++;
            }
        }
        temp.cust=k+1;
        return temp;
    }
    
    
};

int main()
{
    sets setA;
    sets setB;
    sets ABUnion;
    sets c;
    
    cout << "Insert setA : \n";
    setA.add_cust();
    //setA.display();
    
    
    cout << "\nInsert setB : \n";
    setB.add_cust();
    //setB.display();
    
    cout << "Union operation of setA and setB : \n";
    c = setA.ABUnion(setB);
    c.display();

    
    
    return 0;
}
