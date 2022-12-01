#include <iostream>

using namespace std;

class Set
{
private:
    int n;
    string name[20];


public:
    void read();
    void display();
    void unionofsets(Set c);
    void intersection(Set c);

};

void Set :: read(){
    cout << "Enter no of customers : ";
    cin >> n;
    cout << "Enter name of customers  : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }  
}

void Set :: display(){
    cout << "Displaying elements of set  : "<<endl;
    for (int i = 0; i < n; i++)
    {
    cout << name[i] << "\t";
       
    }
}

void Set :: unionofsets(Set setB){
    int n2 = setB.n;
    Set temp;
    int flag;
    //cout << n2;
    // printing elements of set a
    for (int i = 0; i < n; i++)
    {
        temp.name[i]=name[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << temp.name[i] << "\t";
    }
    

    //checking common elements in both set
    for (int j = 0; j < n2; j++)
    {
    flag = 0;
        for (int k = 0; k < n; k++)
        {
            if (setB.name[j]==temp.name[k])
            {
                flag=1;
                break;
                
            } 
        }
        if (flag!=1)
        {
            cout << setB.name[j] << "\t";
        }
         
    }


}

    void Set :: intersection(Set setB){
        int n2 = setB.n;
        int flag,count=0;
        for (int i = 0; i < n; i++)
        {
            flag=0;
            for (int j = 0; j < n2; j++)
            {
                if (name[i]==setB.name[j])
                {
                    flag=1;
                    break;
                }
                
            }
            if (flag==1)
            {
                count++;
                cout << name[i] << "\t";              
            }
        }
        
            if (count==0)
            {
                cout << "None"<< endl;
            }

    }

int main(){

    Set setA;
    Set setB;
    Set c;

    cout << "Enter customers who likes pizza : "<<endl;
    setA.read();
    //setA.display();

    cout << "\nEnter customers who likes Burger : "<<endl;
    setB.read();
    //setB.display();

    cout << "\n\nSet of customers who like either pizza or burger or both : "<<endl;
    setA.unionofsets(setB);

    cout << "\n\nSet of customers who like both pizza and burger : "<<endl;
    setA.intersection(setB);






    return 0;
}
