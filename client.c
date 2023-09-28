#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h> 
#include <sys/types.h>
#include <unistd.h>
#include "header.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main(void){
    MESSAGE msg;
    int res;
    int requests, responses;

    requests = msgget(REQUEST_KEY, 0700 | IPC_CREAT); 
    if (requests == -1) { 
        perror("msgget"); 
        return (EXIT_FAILURE); 
    } 

    responses = msgget(RESPONSE_KEY, 0700 | IPC_CREAT); 
    if (responses == -1) { 
        perror("msgget"); 
        return (EXIT_FAILURE); 
    }

    printf("Entrez votre message : ");
    fgets(msg.mtext, LG_MAX, stdin);

    msg.mtype = getpid();
    res = msgsnd(requests,&msg,strlen(msg.mtext)+1,0);

    res = msgrcv(responses,&msg,LG_MAX,0,0);

    printf("result : %s\n", msg.mtext);
    return EXIT_SUCCESS;

}