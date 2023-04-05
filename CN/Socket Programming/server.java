    import java.net.*;  
    import java.io.*;  

    class server{  
    public static void main(String args[])throws Exception{  

    // at server side create a serversocket and socket to accept request of clien 
    ServerSocket ss=new ServerSocket(PORT_NUMBER);  
    Socket s=ss.accept();  

    System.out.println("Client connected!");
    
    // set streams to read and write 
    DataInputStream din=new DataInputStream(s.getInputStream());  
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
      
    String str="",str2="";  

    while(!str.equals("stop")){  
        str = din.readUTF();  
        System.out.println("Message from client : "+str);  
        str2 = br.readLine();  
        dout.writeUTF(str2);  
        dout.flush();  
    }  
    din.close();  
    s.close();  
    ss.close();  
    }}  
