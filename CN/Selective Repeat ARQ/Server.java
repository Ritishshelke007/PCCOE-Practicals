import java.net.*;
import java.util.Scanner;
import java.io.*; 


    class Server{  
    public static void main(String args[])throws Exception{  
    Scanner sc = new Scanner(System.in);

    System.out.println("======Server======");
    ServerSocket ss = new ServerSocket(4444);
    Socket s = ss.accept();
    System.out.println("Client Connected!");

    DataInputStream din=new DataInputStream(s.getInputStream());  
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
    
    int n, change_index;
   // int frame_data[] = {50,100,40,15,85};

    System.out.println("How many frames do you want to send");
    n = sc.nextInt();

    int frame_data[] = new int[n];

    System.out.println("Enter data frames");
    for(int i=0;i<n;i++){
        frame_data[i] =  sc.nextInt();
    }


    dout.write(n);

    for(int i=0; i<n; i++){
        System.out.println("Sending Frame no : "+i+ " Data is : "+frame_data[i]);
        dout.write(frame_data[i]);
    }

    System.out.println("All frames are sent !");

    System.out.println("Enter frame no to change data ");
    change_index = sc.nextInt();


    frame_data[change_index] = -1;
 
    for(int j=0; j<n; j++){
        System.out.println("Sending Frame no : "+j+ " Data is : "+frame_data[j]);
        dout.write(frame_data[j]);
    }

    dout.close();  
    s.close();  
    }}  
