    import java.net.*;  
    import java.io.*;  


    class client{  
    public static void main(String args[])throws Exception{  

    Socket s = new Socket("SERVER_IP_ADDRESS",PORT_NUMBER);

    DataInputStream din=new DataInputStream(s.getInputStream());  
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  

    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
      
    String str="",str2="";  
    while(!str.equals("stop")){  
        str=br.readLine();  
        dout.writeUTF(str);  
 
        dout.flush();
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
