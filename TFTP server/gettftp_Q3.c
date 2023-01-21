#include "fonctions.h"

int main(int argc, char ** argv){
	
	if (argc==3){
		printf("Not enough argument\n");
		return EXIT_FAILURE;
	}
	print_info(argv);
	
	struct addrinfo hint = init_addr();
	struct addrinfo *res;
	
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

	return EXIT_SUCCESS;
	
}









