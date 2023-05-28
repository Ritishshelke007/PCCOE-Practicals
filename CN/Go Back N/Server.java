import java.util.*;
import java.io.*;
import java.net.*;


public class Server {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int i=0;

        ServerSocket ss = new ServerSocket(4444);
        System.out.println("=======Server=======");
        Socket s = ss.accept();
        System.out.println("Client connected");

        DataInputStream in = new DataInputStream(s.getInputStream());
        DataOutputStream out = new DataOutputStream(s.getOutputStream());

        int frames = in.read();
        System.out.println("No of frames to send : "+frames);
        
        boolean status[] = new boolean[frames]; 

        int choice = in.read();

        if(choice==0){

            for(i=0;i<frames;i++){
                System.out.println("Sending frame no : "+i);
                out.write(i);
                out.flush();
                int j = in.read();
                System.out.println("ACK received for frame "+i+" as "+j);
                System.out.println("\n");
            }
        }
        else{
            for(i=0;i<frames;i++){

                if(i==2){
                    System.out.println("Sending frame no : "+i);
                }
                else{
                    System.out.println("Sending frame no : "+i);
                    out.write(i);
                    out.flush();
                    int j = in.read();

                    if(j!=255){

                        System.out.println("ACK received for frame "+i+" as "+j);
                        status[i] = true;
                        System.out.println("\n");
                    }
                    else{
                        System.out.println("Received Negative ACK");
                        status[i] = false;
                    }
                }
            }
            // resending frames 
            for(i=0;i<frames;i++){
                if(status[i]==false){
                    System.out.println("\nResending frame no : "+i);
                    out.write(i);
                    out.flush();
                    int j = in.read();
                    System.out.println("ACK received for frame "+i+" as "+j);
                    status[i]=true;
                }
            }
        }



    } // end main
    
} // end class
