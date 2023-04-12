
#include <iostream>

using namespace std;

class crc{
    public:
    
    int data_bits, divisor_bits, dataword[20], divisor[20], temp[20];
    
    void getData(){
        cout << "***Connected with receiver enter data to send***\n";
        cout << "Enter Dataword size : ";
        cin >> data_bits;
        
        cout << "Enter Divisor size : ";
        cin >> divisor_bits;
        
        cout << "Enter dataword : ";
        for(int i=0; i<data_bits; i++){
            cin >> dataword[i];
        }
        
        cout << "Enter divisor : ";
        for(int i=0; i<divisor_bits; i++){
            cin >> divisor[i];
        }
        
        divisor_bits--;
        
        
         for(int i=0;i<divisor_bits;i++)
            dataword[data_bits+i] = 0;
            
            
        for(int i=0;i<data_bits+divisor_bits;i++)
            temp[i] = dataword[i];
            
        exor_divide(temp, divisor, data_bits, divisor_bits);
    }
    
    
    
    
    void display(){
        cout << "dataword : ";
        for(int i=0; i<data_bits; i++){
            cout << dataword[i];
        }
        
        cout << "divisor : ";
        for(int i=0; i<divisor_bits; i++){
            cout << divisor[i];
        }
    }
    
    void exor_divide(int temp[],int divisor[],int data_bits,int divisor_bits)
        {
         for(int i=0;i<data_bits;i++)
         {
             if (divisor[0]==temp[i])
             {
                 for(int j=0,k=i;j<divisor_bits+1;j++,k++)
                     if(!(temp[k]^divisor[j]))
                         temp[k]=0;
                     else
                         temp[k]=1;
             } 
         }
        }
        
        
    void send_message(){
         cout<<"Genaerated CRC : ";
             for(int i=0;i<divisor_bits;i++)
             {
                 cout<<temp[data_bits+i]<<" ";
                 dataword[data_bits+i] = temp[data_bits+i];
             }
             
             cout<<endl<<"Sending  Message  as : ";
             for(int i=0;i<data_bits+divisor_bits;i++){
                 
                 cout<<dataword[i]<<" ";
             }
    }
    
    void receiver(){
        cout << endl << endl;
        cout << "***Receiving data***"<<endl;
        
        cout<<"Enter the message received to you to check error : ";
         
         for(int i=0;i<data_bits+divisor_bits;i++){
             cin>>dataword[i];
         }
         
             
         for(int i=0;i<data_bits+divisor_bits;i++)
             temp[i] = dataword[i];
             
         exor_divide(temp,divisor,data_bits,divisor_bits);
         
         for(int i=0;i<divisor_bits;i++)
         {
             if(temp[data_bits+i])
             {
                 cout<<"**Message is discarded due to error**";
             }
        }
        
         cout<<"Decoded successfully no error found** : ";
         cout << "Message Send by receiver : " << endl;
         for(int i=0; i<data_bits; i++){
             
             cout<<dataword[i]<<" ";
             
         }
    }
    
};


int main()
{
    crc obj;
    
    obj.getData();
    
    obj.send_message();
    
    obj.receiver();
    
    return 0;
}
