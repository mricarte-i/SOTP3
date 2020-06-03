#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080
//AF_INET = 2

int main(int argc, char **argv){
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){ 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){ 
        printf("\nConnection Failed \n"); 
        return -1; 
    }

    printf("connected!\n"); 
    return 0;
}