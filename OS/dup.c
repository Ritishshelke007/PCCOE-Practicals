#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 

int main(){

	int fd[2];
	
 	int pid;
 	
	int file_desc = open("file.txt", O_RDONLY);
		dup2(file_desc, 0); // or can pass 0
		close(file_desc);
		pipe(fd);
		
		if( (pid = fork()) == 0){
		
		printf("Sort executed by child process..\n");
			
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			
			execl("/usr/bin/sort","sort",(char*)0);
			
			
			
		}
		
		else if( pid > 0 ) { // parent process
		
		printf("Uniq executed by parent process...\n");
		
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			execl("/usr/bin/uniq","uniq",(char*)0);
			
			
		
		}
		
		else {
		
			perror("fork()");
			exit(1);
		}
	
	
	return 0;

}
