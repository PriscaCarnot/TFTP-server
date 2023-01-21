#include "fonctions.h"

void print_info (char ** argv){
	printf("server: %s \n",argv[1]);
	printf("file  : %s \n",argv[2]);
	printf("port  : %s \n",argv[3]);
}

struct addrinfo init_addr(){
	struct addrinfo hint;
		
	//Initialization of an address
	hint.ai_flags=0;
	hint.ai_family=AF_INET; // IPv4
	hint.ai_socktype=SOCK_DGRAM; //Datagram of the socket
	hint.ai_protocol=IPPROTO_UDP; // UDP protocol
	
	return hint;
}

int send_rcv_ack(struct addrinfo *res,int sockfd){
	char msg[len_rcv];
	char ack[len_ACK];
	
	//Receive data from the server
	int lengthrcv=recvfrom(sockfd,&msg,100,res->ai_flags,res->ai_addr,&res->ai_addrlen);
	if (lengthrcv==-1){
		printf("error receiver\n");
		return 1;
	}

	//print the received data
	printf("message received!  :%d \n",lengthrcv);
	for (int i=4;i<lengthrcv;i++){
		printf("%d",msg[i]);
	}
	
	//Initialize the Acknowledge
	ack[0]=msg[0];
	ack[1]=4;
	ack[2]=msg[2];
	ack[3]=msg[3];

	//Send the acknowledge
	sendto(sockfd,&ack,4,res->ai_flags,res->ai_addr,res->ai_addrlen);
	//If the length of the data is shorter than the maximum length possible, this is the last block
	if (lengthrcv!=Max_length_data_rcv){
		return 1;
	}
	return 0;
}
