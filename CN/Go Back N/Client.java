import java.util.*;
import java.io.*;
import java.net.*;


public class Client {
    public static void main(String[] args) throws UnknownHostException, IOException {
        Scanner sc = new Scanner(System.in);
        int j=0;
        int check=0;

        System.out.println("=======Client=======");

        Socket s = new Socket("localhost",4444);

        DataInputStream in = new DataInputStream(s.getInputStream());
        DataOutputStream out = new DataOutputStream(s.getOutputStream());

        System.out.println("Enter number of frames to receive : ");
        int frames = sc.nextInt();


        out.write(frames);
        out.flush();

        System.out.println("Type of Transmission : \n0. Without Error\n1. With Error");
        int choice = sc.nextInt();

        out.write(choice);
        out.flush();


        if(choice==0){

            for(j=0;j<frames;j++){
                int i = in.read();
                System.out.println("Received frame no : "+i);
                System.out.println("Sending ACK of frame : "+i);
                out.write(i);
                out.flush();
                System.out.println("\n");
            }
        }
        else{
            for(j=0;j<frames;j++){
                int i = in.read();

                if(i==check){
                    System.out.println("\nReceived frame no : "+i);
                    System.out.println("Sending ACK of frame : "+i);
                    out.write(i);
                    out.flush();
                    check++;
                }
                else{
                    --j;
                    System.out.println("Discarded frame no : "+i);
                    System.out.println("Sending negative ACK");
                    out.write(-1);
                    out.flush();
                }
            }


        }

        
    }
    
}
