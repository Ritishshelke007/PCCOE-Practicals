#include <iostream>
using namespace std;

class crc{
public:

int dataword_size, divisor_size, dataword[20], divisor[20], temp[20], codeword[20];
int flag=0;

void getData(){
cout << "Enter Dataword size : ";
cin >> dataword_size;

cout << "Enter Divisor size : ";
cin >> divisor_size;

cout << "Enter dataword : ";
for (int i = 0; i < dataword_size; i++)
{
    cin >> dataword[i];
}

cout << "Enter Divisor : ";
for (int i = 0; i < divisor_size; i++)
{
    cin >> divisor[i];
}

cout << "Original dataword : ";
for (int i = 0; i < dataword_size ; i++)
{
   cout << dataword[i];
}


// append divisor-1 0's to dataword

divisor_size--;

for (int i = 0; i < divisor_size; i++)
{
    dataword[dataword_size+i] = 0; 
}

cout << "\nDataword  after padding : ";
for (int i = 0; i < dataword_size+divisor_size ; i++)
{
   cout << dataword[i];
}

// set temp to dataword
for (int i = 0; i < dataword_size+divisor_size ; i++)
{
   temp[i] = dataword [i];
}

cout << "\nTemp value : ";
for (int i = 0; i < dataword_size+divisor_size ; i++)
{
   cout << temp[i];
}

// call crc method

ex_or(temp,divisor,dataword_size,divisor_size);

}

void ex_or(int temp[],int divisor[],int dataword_size,int divisor_size){

for (int i = 0; i < dataword_size; i++)
{
   if (divisor[0] == temp[i])
   {
    for (int j = 0, k=i; j < divisor_size+1; j++,k++)
    {
        if (!(temp[k]^divisor[j]))
        {
            temp[k] = 0;
        }
        else{
            temp[k] = 1;
        }
        
    }
    
   }
}
}

void sender_side(){
    cout << "\nGenerated CRC : ";
    for (int i = 0; i < divisor_size; i++)
    {
        cout << temp[dataword_size+i];
        dataword[dataword_size+i] = temp[dataword_size+i];
    }

    cout << "\nGenerated codeword to send it to receiver : ";
    for (int i = 0; i < dataword_size+divisor_size; i++)
    {
       cout << dataword[i];
    }
    

}

void receiver_side(){
    cout << endl << endl;
    cout << "Enter the codeword you received : ";
    for (int i = 0; i < dataword_size+divisor_size; i++)
    {
        cin >> codeword[i];
    }

    ex_or(codeword,divisor,dataword_size,divisor_size);

    for (int i = 0; i < divisor_size; i++)
    {
        if (codeword[dataword_size+i])
        {           
            flag = 1;
            break;
        }
    }
       // cout << "Decoded successfully!";
       if (flag==1)
       {
        cout << "Error in transmission !";
       }
       else{
        cout << "Correct message is received!";
       }
         
}

};

int main(){

    crc obj;

    obj.getData();

    obj.sender_side();

    obj.receiver_side();

    return 0;
}
