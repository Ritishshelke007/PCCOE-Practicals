import java.net.*;
import java.io.*;  


class Client{  
public static void main(String args[])throws Exception{ 
    
int n;
//int rec_frame_data[] = new int[5];

System.out.println("======Client======");
Socket s=new Socket("localhost",4444);  

DataInputStream din=new DataInputStream(s.getInputStream());  
DataOutputStream dout=new DataOutputStream(s.getOutputStream());  

n  = din.read();

int rec_frame_data[] = new int[n];

System.out.println("No of frames you will be recieving from Server are : "+n);
System.out.println("---------------Ready to receive frames------------\n");

for(int i=0; i<n; i++){
    rec_frame_data[i]  = din.read();
        System.out.println("Frame no : "+ i + " Received data : "+ rec_frame_data[i]);
}

System.out.println("----Receiving again----");

for(int i=0; i<n; i++){
    rec_frame_data[i]  = din.read();
    System.out.println("Frame no : "+ i + " Received data : "+ rec_frame_data[i]);
}


din.close();  
s.close();  

}}  
