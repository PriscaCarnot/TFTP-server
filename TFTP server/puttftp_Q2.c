#include "fonctions.h"

int main(int argc, char ** argv){
	if (argc!=4){
		printf("Not enough argument\n");
		return EXIT_FAILURE;
	}
	print_info(argv);
	
	struct addrinfo hint;
	struct addrinfo *res;
		
	//Initialization of an address server
	hint.ai_flags=0;
	hint.ai_family=AF_INET; // IPv4
	hint.ai_socktype=SOCK_DGRAM; //Datagram of the socket
	hint.ai_protocol=IPPROTO_UDP; // UDP protocol
	
	//Retrieve the server address
	int erraddr=getaddrinfo(argv[1],argv[3],&hint,&res);
	if (erraddr!=0){
		printf("error address\n");
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
