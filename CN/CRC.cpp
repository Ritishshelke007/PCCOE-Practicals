#include<iostream>
#include<string.h>
using namespace std;

class CRC {
	

	string input,divisor,divident,result;
	
	int len_divident, len_gen, len_inp;

public:
	string fun_xor(string a,string b)
	{
		string result="";
		if(a[0]=='0')
		return a.substr(1);
		else
		{
			for(int i=0;i<len_gen;i++)
			{
				result=result+(a[i]==b[i]?'0':'1');
			}
			
			return result.substr(1);
		}
	}
	void  modulo_div()
	{
		
		string temp_div=divisor;
		string temp_divident=divident.substr(0,len_gen);
		int j=len_gen;
		while(j<len_divident)
		{
			temp_divident=fun_xor(temp_divident,temp_div);
			temp_divident=temp_divident+divident[j];
			j++;
		}
		result=input+fun_xor(temp_divident, temp_div);
	
		
	}
	void getdata()
	{
		
		cout<<"\nEnter Input: ";
		cin>>input;
		cout<<"\nEnter coefficients of generator polynomial: ";
		cin>>divisor;
		
		len_gen=divisor.length();
		len_inp=input.length();
		divident=input;
		int r=len_gen-1;
		for(int i=0;i<r;i++)
		{
			divident=divident+'0';		
		}
		len_divident=divident.length();
		
		modulo_div();
		
		
		
	}
	void sender_side()
	{
		cout<<"Input: "<<input<<"\n";
		cout<<"Polynomial: "<<divisor<<"\n";
		cout<<"Divident: "<<divident<<"\n";
		cout<<"Data to send: "<<result<<"\n";
		
	}
	void receiver_side()
	{
		string data_rec;
		cout<<"\nEnter Data Received: ";
		cin>>data_rec;

		string temp_div=divisor;
		string temp_divident=data_rec.substr(0,len_gen);
		int j=len_gen;
		while(j<data_rec.length())
		{
			temp_divident=fun_xor(temp_divident,temp_div);
			temp_divident=temp_divident+data_rec[j];
			j++;
		}
		string error=fun_xor(temp_divident, temp_div);
		cout<<"reminder is: "<<error;

		bool flag=0;
		for(int i=0;i<len_gen-1;i++)
		{
			if(error[i]=='1')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		cout<<"\nCorrect Data Received Without Any Error";
		else
		cout<<"\nData Received Contain Some  Error";
			
		
		
	}

	

};
 int main() {
	// TODO Auto-generated method stub
	 CRC crc;
	 crc.getdata();
	 crc.sender_side();
	 crc.receiver_side();
	 return 0;
}
