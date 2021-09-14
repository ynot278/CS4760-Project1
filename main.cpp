//Author: Tony Pham Sept 14, 2021

#include "driver.h"

int main(int argc, char* argv[]) {

	char type = 'W';
	string msg = "computer is overheating";

	int seconds;
	int opt;

	if(argc == 1){
		const char* filename = "messages.log";
		savelog(filename, msg, type);
		exit (EXIT_SUCCESS);
	}
	
	while((opt = getopt(argc, argv, "ht:")) != -1){
		switch(opt){
			case 'h':
				helpMenu();
				break;
			case 't': 
				seconds = atoi(optarg);
				seconds = rand() % (2*seconds + 1) + 0;
				getlog(msg, type);
				sleep(seconds);
				exit (EXIT_SUCCESS);
				break;
			default: 
				exit (EXIT_FAILURE);
				break;
		}
	}

	if((opt = getopt(argc, argv, "ht:")) != 1){
		string filename = argv[1];
		savelog(filename, msg, type);
	}
}