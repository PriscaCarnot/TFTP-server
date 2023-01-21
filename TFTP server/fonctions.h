#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define len_rcv 558
#define len_ACK 4
#define Max_length_data_rcv 100

void print_info(char** argv);
struct addrinfo init_addr();
int send_rcv_ack(struct addrinfo *res,int sockfd);
