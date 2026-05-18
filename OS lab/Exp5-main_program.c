#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid = fork();
    if(pid<0){
        perror("Fork Failed");
    }
    else if(pid == 0){
        printf("Child process: pid = %d executing myadder\n",getpid());
        char *args[] = {"./myadder","5","10",NULL};
        execv(args[0],args);
        perror("Exec Failed");
        exit(1);
    }
    else{
        printf("Parent process: pid = %d waiting for child to finish\n",getpid());
        wait(NULL);
        printf("Child process finished execution\n");
    }
}