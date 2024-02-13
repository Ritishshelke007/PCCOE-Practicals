#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main(){

	int choice,conti;
	int pipedes[2];
	int returnstatus;
 	int pid;
	char writemessages[2][20]={"Hi from Parent", "Hello"};
	char readmessage[20];
	int file_desc;
	
	do{
	
	printf("1. pipe()\n2. dup2()\nEnter Choice : ");
	scanf("%d",&choice);
	
	switch(choice){
	
	case 1:

		   
		   returnstatus = pipe(pipedes);
		   
		   if (returnstatus == -1) {
		      printf("Unable to create pipe\n");
		      return 1;
		   }
		   
		   pid = fork();
		   		    
		   if (pid == 0) {
		   
		      read(pipedes[0], readmessage, sizeof(readmessage));
		      
		      printf("\nChild Process - Reading from pipe – Received Message 1 : %s\n", readmessage);
		      
		      read(pipedes[0], readmessage, sizeof(readmessage));
		      
		      printf("Child Process - Reading from pipe – Received Message 2 : %s\n", readmessage);
		   } 
		   else { 
		      printf("Parent Process - Writing to pipe - Message 1 : %s\n", writemessages[0]);
		      
		      write(pipedes[1], writemessages[0], sizeof(writemessages[0]));
		      
		      
		      printf("Parent Process - Writing to pipe - Message 2 : %s\n", writemessages[1]);
		      
		      write(pipedes[1], writemessages[1], sizeof(writemessages[1]));
		   }
		
		
		break;
	
	case 2:
	
		file_desc = open("file.txt",O_WRONLY | O_APPEND); 
	      
	    	dup2(file_desc, 1) ;  
		  	    
	    	printf("Line 1 -> This will be printed in the file file.txt\n"); 
	    	printf("Line 2 -> This will be printed in the file file.txt\n"); 
	
		exit(0);
	
		break;
		
	default:
		printf("Invalid Choice\n");
	
	
	}
	
	
	
	
	printf("Press 1 to continue : ");
	scanf("%d",&conti);
	}
	while(conti == 1);
	
	
	
	
	
	return 0;

}
