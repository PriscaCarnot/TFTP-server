#include "fonctions.h"

//port 1069


int main(int argc, char ** argv){
	// Verify the right number of input argument
	if (argc!=4){
		printf("Not enough argument\n");
		return EXIT_FAILURE;
	}
	// retrieve server address
	printf("server: %s \n",argv[1]);
	printf("file  : %s \n",argv[2]);
	printf("port  : %s \n",argv[3]);
	return EXIT_SUCCESS;
}









