#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "port.h"
#include <stdlib.h>
#include <netinet/in.h>

#define MAX_LEVEL 10
#define MAX_LENGTH_BUFFER 2000

//función para limpiar la pantalla 
void clear_screen(){
    printf("\033[1;1H\033[2J"); 
}

// RESPUESTAS DE LOS ACERTIJOS
char *answers[11]={
    "entendido\n",  //respuesta del acertijo 1
    "0854780\n",    //respuesta del acertijo 2
    "martin luther king\n",  //respuesta del acertijo 3
    "es_go_lo_dro_bo\n",  //respuesta del acertijo 4
    "too_easy\n",  //respuesta del acertijo 5
    ".RUN_ME\n",  //respuesta del acertijo 6
    "in_de_ter_mi_na_do\n",  //respuesta del acertijo 7
    "thunder thunder thunder thundercats\n",  //respuesta del acertijo 8
    "this is awesome\n",  //respuesta del acertijo 9
    "chin_chu_lan_cha\n",  //respuesta del acertijo 10
    "gdb_manda\n"  //respuesta del acertijo 11
};

char * logo[29]={

    "___________________________________________(###############/___________________________________________\n",
    "____________________________________###.........................###____________________________________\n",
    "________________________________##...................................##________________________________\n",
    "____________________________##...........................................#&____________________________\n",
    "__________________________#.................................................#__________________________\n",
    "_______________________&#..........................................########...#/_______________________\n",
    "______________________#................................#################....##..#______________________\n",
    "____________________#..........................###############.........#########..#____________________\n",
    "___________________#......................###..##################################&.#___________________\n",
    "__________________#....................##....######################################.#__________________\n",
    "_________________#...................##...####################..&##################&.#_________________\n",
    "________________#.................##...############################&..##############.&#________________\n",
    "________________#.............&#######################################..#############.#________________\n",
    "_______________*#.........&#############################################.############.#________________\n",
    "_______________##......#################################################..###########.#(_______________\n",
    "_______________/#....####################...........#####################.###########.#._______________\n",
    "________________#.&#################..................##################..###########.#________________\n",
    "________________#....#############....................##################.&###########.#________________\n",
    "_________________##...#########.......................################..........####.#_________________\n",
    "_________________.#....#######........................##############&.............#.#__________________\n",
    "___________________#......####&......................###########...................#___________________\n",
    "____________________##......####....................########......................#____________________\n",
    "_____________________###.......###.................#######.....................###_____________________\n",
    "_______________________##........................#########.....#..............##_______________________\n",
    "_________________________##............&##&&##################..............##_________________________\n",
    "____________________________##..............################.............##____________________________\n",
    "_______________________________##...........#..##########.............##_______________________________\n",
    "___________________________________.##...........................##/___________________________________\n",
    "__________________________________________######&&...&#######__________________________________________\n"
};



void level1(void);
void level2(void);
void level3(void);
void level4(void);
//void level5(void);
void level6(void);
void level7(void);
void level8(void);
void level9(void);
void level10(void);
void level11(void);




// arreglo con todos los niveles del juego
void (*level[MAX_LEVEL])(void) = {level1, level2, level3, level4, level6, level7, level8, level9, level10, level11};

// función para conectar el server con el cliente a través de un socket
int initialize_server(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    FILE *stream;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0){
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return new_socket;
}

   

void game(int socket){
    
    //(se podria validar)
    //todas las rtas del cliente vienen por el socket.
    FILE* stream = fdopen(socket, "r");
    char *buffer = NULL;
	size_t buffer_size = MAX_LENGTH_BUFFER;
	int i;

    for(i = 0; i < MAX_LEVEL; i++){
    	int solved = 0;
        while(!solved){
            level[i]();
            if(getline(&buffer, &buffer_size, stream) == -1){
              //close(server_fd);
              //close(socket);
              //close(stream);
                perror("getline");
                exit(1);
            }
            if(strcmp(buffer, answers[i]) == 0){
                solved = 1;
                printf("Level completed!\ngood for you\n");
                sleep(2);
           }else{
                printf("Wrong answer: %s\n", buffer);
                sleep(2);
            }
            clear_screen();
    	}
	}
	clear_screen();
	printf("Congratulations!! You won the game.\n"); 
 	//close(server_fd);
 	//close(socket);
  	//close(stream);
  	return;
}

void gdbme(){
    if(1 == 0){

    }else{
        perror("getline");
        exit(EXIT_FAILURE);
    }
}

void mixer(){
    time_t t;
    char c;
    char v[]= "La respuesta es in_de_ter_mi_na_do\n";
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    int i, n = 36;
    /* Print 5 random numbers from 0 to 49 */
    for( i = 0 ; i < n ; i++ ) {
        c = 33 + rand()%(127-33);
        write(1, v + i, 1);
        write(2, &c, 1);
    }
}

//-----------------------LEVEL CLUES-------------------------------------
void level1()
{
    printf("------------- LEVEL:1 -------------\n");
    printf("Welcome to the game and congratulations !! You have solved the first challenge.\n");
    printf("To verify that your answers are in the correct format, answer this challenge with the word 'entendido' \n");
}

void level2(){
    printf("------------- LEVEL:2 -------------\n");
    printf("HASHTAG left up up left down right down left ASTERISK\n");
}

void level3(){
    printf("------------- LEVEL:3 -------------\n");
    printf("https://voca.ro/hcmH7cqyqTg\n");
}

void level4(){
    printf("------------- LEVEL:4 -------------\n");
    char rsp[] = "The answer to this puzzle is es_go_lo_dro_bo\n";
    write(13, rsp, strlen(rsp));
    printf("EBADF...\n");
    printf("write: Bad file descriptor\n");
}

void level6(){
    printf("------------- LEVEL:6 -------------\n");
    printf("... -s ... : ... .got .got.plt .data .comment ?\n");
}


void level7(){
    printf("------------- LEVEL:7 -------------\n");
    printf("mixed fds\n");
    mixer();
}


void level8(){

    printf("------------- LEVEL:8 -------------\n");
    printf("logo\n\n\n");

    int i;

    for( i=0; i<29 ;i++){
        printf("%s",logo[i]);
    }

    printf("\n\n");

}




void level9(){
    printf("------------- LEVEL:9 -------------\n");
    printf("Tango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n");
}


void level10(){
    printf("------------- LEVEL:10 -------------\n");
    system("gcc quine.c -o quine");
    if( system("./quine | diff - quine.c") != 0 ){
        write(2, "Not the expected result\n", 24);
        exit(EXIT_FAILURE);
    }

    printf("The answer to this puzzle is chin_chu_lan_cha\n");
}

void level11(){
    printf("------------- LEVEL:11 -------------\n");
    printf("b gdbme\n");
    gdbme();
}


int main(int argc, char const *argv[]) {
    int socket = initialize_server();
    game(socket);

    return 0;
}










