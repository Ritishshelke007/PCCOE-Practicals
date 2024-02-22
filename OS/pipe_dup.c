#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main(){

	int choice,conti;
	int pipedes[2];
	int fd[2];
	int returnstatus;
 	int pid;
 	int pid2;
	char writemessages[2][20]={"Hi from Parent", "Hello"};
	char readmessage[20];
	int file_desc;
	
	do{
	
	printf("\n1. pipe()\n2. dup2()\nEnter Choice : ");
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
	
		
		file_desc = open("file.txt", O_RDONLY);
		dup2(file_desc, 0); // or can pass 0
		close(file_desc);
		pipe(fd);
		
		if( (pid2 = fork()) == 0){
		printf("Sort executed by child process...\n");
			
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			
			execl("/usr/bin/sort","sort",(char *) 0);
			
		}
		
		else if( pid > 0 ) { // parent process
		printf("\nUniq executed by parent process...\n");
		
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			execl("/usr/bin/uniq","uniq",(char *) 0);
		
		}
		
		else {
		
			perror("fork()");
			exit(1);
		}
	
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
