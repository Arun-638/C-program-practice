#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid = fork();
    if(pid<0){
        perror("Fork failed");
    }
    else if(pid==0){
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else{
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(1); // Sleep to ensure child process finishes before parent exits
    }
}