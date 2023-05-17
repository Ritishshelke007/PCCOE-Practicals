import java.io.*;
import java.net.*;
import java.util.*;
public class DNSAssignment{
public static void main(String args[]){

	Scanner sc=new Scanner(System.in);
	String website,uip;
	//int addr[]=new int[4];
	//byte addr2[]=new byte[4];
	
	try{
	System.out.println("Enter the website to get ip :");
	website=sc.next();
	
	InetAddress ia=InetAddress.getByName(website);
	
	System.out.println("\nWebsite name:"+website+"\nIp :"+ia.getHostAddress());
	
	System.out.println("Enter the Ip to get website name :");
	uip=sc.next();
	
	
	for(int i=0;i<4;i++){
	
		//addr[i]=sc.nextInt();
		
		//addr2[i]=uip.split(".").getBytes();
	}
	
	
	InetAddress ia2 =  InetAddress.getByName(uip);  

	
	
	System.out.println("\nIP Given by user:"+uip);
	
	
	System.out.println("\nHost name of ip:"+ia2.getHostName());
	
	}catch(Exception e){
	}
}}
