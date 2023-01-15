#include <iostream>
using namespace std;

void display(string name[], int count){
    for (int i = 0; i < count; i++)
    {
        cout << name[i] << " ";
    }
    cout << endl;
    
}

void sort_names(string name[], int count){
    string temp;

    for (int i = 0; i < count; i++)
    {   
        for (int j = i+1; j < count; j++)
        {
            if (name[i]>name[j])
            {
                temp=name[i];
                name[i]=name[j];
                name[j]=temp;
            }
            
        }
        
    }

    cout << "-----After sorting----"<<endl;
    display(name,count);
    
}

int main(){
    int count;
    cout << "No of names to sort : ";
    cin >> count;

    string name[count];

    cout << "Enter names : "<<endl;
    for (int i = 0; i < count; i++)
    {
        cin >> name[i];
    }

    cout << "-----Before sort : ------"<<endl;

    display(name,count);
    sort_names(name,count);
    

    return 0;
}
