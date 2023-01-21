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
	int nb=0;
	
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
	buff[nb++]=(uint16_t) 0;
	buff[nb++]=(uint16_t) 1;
	strcpy(&buff[nb],argv[2]);
	nb=nb+1+strlen(argv[2]);
	strcpy(&buff[nb],"octet");
	
	//Send the RRQ request to the server
	int err=sendto(sockfd,buff,length_buff,res->ai_flags,res->ai_addr,res->ai_addrlen);
	if (err==-1){
		printf("Error : message could not be sent\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	
}









