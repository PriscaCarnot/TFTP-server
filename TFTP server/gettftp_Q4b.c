#include "fonctions.h"


int main(int argc, char ** argv){
	
	if (argc==3){
		printf("Not enough argument\n");
		return EXIT_FAILURE;
	}
	print_info(argv);
	
	struct addrinfo hint = init_addr();
	struct addrinfo *res;
	int length_buff=9+strlen(argv[2]);
	char buff[length_buff];
	int count=0;
	char msg_rcv[len_rcv];
	char Ack[len_ACK];
	
	//Retrieve the server address
	int erraddr=getaddrinfo(argv[1],argv[3],&hint,&res);
	if (erraddr!=0){
		printf("error address\n");
		return EXIT_FAILURE;
	}
	
	//Connection socket to the server
	int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if (sockfd==-1){
		printf("Error : Connection socket not established\n");
		return EXIT_FAILURE;
	}
	
	//Creation of the RRQ request
	buff[count++]=(uint16_t) 0;
	buff[count++]=(uint16_t) 1;
	strcpy(&buff[count],argv[2]);
	count=count+1+strlen(argv[2]);
	strcpy(&buff[count],"octet");
	
	//Send the RRQ request to the server
	int err=sendto(sockfd,&buff,length_buff,res->ai_flags,res->ai_addr,res->ai_addrlen);
	if (err==-1){
		printf("Error : message could not be sent\n");
		return EXIT_FAILURE;
	}
	
	//Receive the message
	int lengthrcv=recvfrom(sockfd,&msg_rcv,len_rcv,res->ai_flags,res->ai_addr,&res->ai_addrlen);
	if (lengthrcv==-1){
		printf("error receiver\n");
		return EXIT_FAILURE;
	}
	
	//Initialize the Acknowledge
	Ack[0]=msg_rcv[0];
	Ack[1]=4;    //Identify as an acknowledge
	Ack[2]=msg_rcv[2];
	Ack[3]=msg_rcv[3];
	
	//Send the Acknowledge
	int errAck=sendto(sockfd,&Ack,4,res->ai_flags,res->ai_addr,res->ai_addrlen);
	if (errAck==-1){
		printf("Error : acknowledge could not be sent\n");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
	
}









