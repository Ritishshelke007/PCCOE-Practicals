    import java.net.*;  
    import java.io.*;  


    class client{  
    public static void main(String args[])throws Exception{  

    // at client side socket is necessary
    Socket s = new Socket("SERVER_IP_ADDRESS",PORT_NUMBER);

    // for both read and write set streams
    DataInputStream din=new DataInputStream(s.getInputStream());  
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
    // set a buffered reader 
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
      
    // initialize strings to store read and write message     
    String str="",str2="";  
    while(!str.equals("stop")){  
        str=br.readLine();  
        dout.writeUTF(str);  
 
        dout.flush();
        
     // handle exception when stop is receeived 
        try{
        str2=din.readUTF();  
        System.out.println("Message from Server : "+str2); 

        }  
        catch(Exception e){
            System.out.println("Exception when receiving message from server");
        }
    }  
      
    dout.close();  
    s.close();  
    }}  
