#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){

int choice;
int status;
int conti;

do{
	printf("1. Create new process (using fork()) \n2. execl()\n3. Copy\n: ");
	scanf("%d", &choice);
	
	switch(choice){
	
	case 1:
		pid_t pid = fork();
		
		if(pid == 0){
		printf("Child process is created!\n");
		printf("PID of child process : %d\n", getpid());
		}

		if(pid > 0){
			printf("It's a parent process with PID : %d\n",getpid());
			pid = wait(&status);
			printf("End of process : %d\n", getpid());
		}

		if(WIFEXITED(status)){
		printf("Process ended with exit(%d)\n",WEXITSTATUS(status));
		}
		
		break;
		
	case 2:
		execl("/bin/ls", "ls","/home/pccoe/RITISH/",(char *)0);
		perror("In execl()");
		
		break;
		
	case 3:
		char *command[3] = {"cp","a.txt","b.txt"};

		if(strcmp(command[1], command[2])!=0){

			char fs[100];

			FILE *fptr;
			fptr=fopen(command[1],"r+");

			if(fptr){
			FILE *fn=fopen(command[2],"a");
			
				while(fscanf(fptr,"%s",fs)!=EOF){
					fprintf(fn,"%s ",fs);
				}
				printf("Content copied success!");
			}else{
				printf("\n Opps.....File does not exist or failed to open..");
			}
		}
		else{
			printf("Both files are same!");
		}
		
		
		break;
		
	default:
		printf("Invalid choice! ");
			
}
printf("\nEnter 1 to continue : ");
scanf("%d", &conti);	
	
}
while(conti==1);
}
