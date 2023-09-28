#define REQUEST_KEY         0x00012345
#define RESPONSE_KEY        0x00012346 
#define LG_MAX              512

typedef struct { 
    long mtype;
    char mtext[ LG_MAX ]; 
} MESSAGE; 
