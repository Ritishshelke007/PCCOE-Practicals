import java.net.*;
import java.io.*;  
import java.lang.*;

class Server{  
public static void main(String args[])throws Exception{ 
    
int n;
int rec_frame_data[] = new int[5];

ServerSocket ss=new ServerSocket(3334);  
Socket s=ss.accept();  

System.out.println("Client connected!");

DataInputStream din=new DataInputStream(s.getInputStream());  
DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  

n  = din.read();
System.out.println("No of frames you will be recieving from client are : "+n);
System.out.println("---------------Ready to receive frames------------\n");

for(int i=0; i<n; i++){
    rec_frame_data[i]  = din.read();
   // Thread.sleep(1200);
    System.out.println("Frame no : "+ i + " Received data : "+ rec_frame_data[i]);
}

// if(i==(n-1)){
//     System.out.println("-----All frames are received!-----");
// }
// else{
//     System.out.println("May one or more frames are list");
// }

System.out.println("Receiving again----");

for(int i=0; i<n; i++){
    rec_frame_data[i]  = din.read();
    // Thread.sleep(1200);
    System.out.println("Frame no : "+ i + " Received data : "+ rec_frame_data[i]);
}


// int changed_add = din.read();
// System.out.println(changed_add);

// int changed_val = din.read();
// System.out.println("Changed to : "+changed_val);

din.close();  
s.close();  
ss.close();  
}}  
