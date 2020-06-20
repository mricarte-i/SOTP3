#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include "port.h"

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
    char* gotcha = "entendido\n";
    send(sockfd , gotcha , strlen(gotcha) , 0 ); 
    printf("1\n");


    char* hashtag = "0854780\n";
    send(sockfd , hashtag , strlen(hashtag) , 0 ); 
    printf("2\n");


    char* mlk = "martin luther king\n";
    send(sockfd , mlk , strlen(mlk) , 0 ); 
    printf("3\n");


    char* la_respuesta = "es_go_lo_dro_bo\n";
    send(sockfd , la_respuesta , strlen(la_respuesta) , 0 );
    printf("4\n");

    char* too_easy = "too_easy\n";
    send(sockfd , too_easy , strlen(too_easy) , 0 );
    printf("5\n");


    char* run_me = ".RUN_ME\n";
    send(sockfd , run_me , strlen(run_me) , 0 );
    printf("6\n");


    char* indeterminado = "in_de_ter_mi_na_do\n";
    send(sockfd , indeterminado , strlen(indeterminado) , 0 );
    printf("7\n");


    char* thunderCats = "thunder thunder thunder thundercats\n";
    send(sockfd , thunderCats , strlen(thunderCats) , 0 );
    printf("8\n");


    char* awesome = "this is awesome\n";
    send(sockfd , awesome , strlen(awesome) , 0 );
    printf("9\n");

    char* chin_chu_lan_cha = "chin_chu_lan_cha\n";
    send(sockfd , chin_chu_lan_cha , strlen(chin_chu_lan_cha) , 0 );
    printf("10\n");

    char* gdbme = "gdb_manda\n";
    send(sockfd , gdbme , strlen(gdbme) , 0 );
    printf("11\n");

    return 0;
}