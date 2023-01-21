#include "fonctions.h"

int main(int argc, char ** argv){
	if (argc!=4){
		printf("Not enough argument\n");
		return EXIT_FAILURE;
	}
	printf("server: %s \n",argv[1]);
	printf("file  : %s \n",argv[2]);
	printf("port  : %s \n",argv[3]);
	
	return EXIT_SUCCESS;
}
