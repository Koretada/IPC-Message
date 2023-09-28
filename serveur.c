#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h> 
#include "header.h"
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

int main(void){
    int requests, responses;
    int counter = 0;
    MESSAGE msg;
    int res;

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
    while(1){
        printf("Attendons la requête...\n");
        res = msgrcv(requests, & msg, LG_MAX, 0, 0);
        printf("Résultat de la requête : %s",msg.mtext);
                
        res = msgsnd(responses, & msg, strlen(msg.mtext) + 1, 0); 
    }

}