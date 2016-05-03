#include<sys/types.h>
#include"ourhdr.h"
int glob=6;
char buf[]="a write to stdout\n";
int main(void){
    int var;
    pid_t pid;
    var=88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)==-1)
        err_sys("write error");
    printf("before fork\n");
    if((pid=fork())==-1) err_sys("fork error");
    else if(pid==0){
        glob++;  
        var++;
    }
    else{
        sleep(2);
    }
    printf("pid=%d,glob=%d,var=%d\n",getppid(),glob,var);
    
}