#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "port.h"
#include <stdlib.h>
#include <netinet/in.h>

void clean_provider( char* the_provider ){
    while( *the_provider ){
        *the_provider++ = 0;
    }
}

int main(int argc, char **argv){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }


    char* gotcha = "entendido\n";
    char the_provider[50] = {0};

    read(new_socket, the_provider, strlen(gotcha));

    if( strcmp( the_provider, gotcha ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }

    printf("1\n");
    clean_provider(the_provider);

    char* hashtag = "0854780\n";
    read(new_socket, the_provider, strlen(hashtag));

    if( strcmp( the_provider, hashtag ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("2\n");
    clean_provider(the_provider);

    char* mlk = "martin luther king\n";
    read(new_socket, the_provider, strlen(mlk));

    if( strcmp( the_provider, mlk ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("3\n");
    clean_provider(the_provider);


    char* la_respuesta = "es_go_lo_dro_bo\n";
    read(new_socket, the_provider, strlen(la_respuesta));

    if( strcmp( the_provider, la_respuesta ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("4\n");
    clean_provider(the_provider);

    char* too_easy = "too_easy\n";

    read(new_socket, the_provider, strlen(too_easy));
    if( strcmp( the_provider, too_easy ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("5\n");
    clean_provider(the_provider);

    char* run_me = ".RUN_ME\n";
    read(new_socket, the_provider, strlen(run_me));

    if( strcmp( the_provider, run_me ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("6\n");
    clean_provider(the_provider);


    char* indeterminado = "in_de_ter_mi_na_do\n";
    read(new_socket, the_provider, strlen(indeterminado));

    if( strcmp( the_provider, indeterminado ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("7\n");
    clean_provider(the_provider);


    char* thunderCats = "thunder thunder thunder thundercats\n";
    read(new_socket, the_provider, strlen(thunderCats));

    if( strcmp( the_provider, thunderCats ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("8\n");
    clean_provider(the_provider);


    char* awesome = "this is awesome\n";
    read(new_socket, the_provider, strlen(awesome));

    if( strcmp( the_provider, awesome ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("9\n");
    clean_provider(the_provider);


    char* chin_chu_lan_cha = "chin_chu_lan_cha\n";
    read(new_socket, the_provider, strlen(chin_chu_lan_cha));

    if( strcmp( the_provider, chin_chu_lan_cha ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("10\n");
    clean_provider(the_provider);


    char* gdbme = "gdb_manda\n";
    read(new_socket, the_provider, strlen(gdbme));

    if( strcmp( the_provider, gdbme ) != 0 ){
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    printf("11\n");
    clean_provider(the_provider);

    return 0;
}