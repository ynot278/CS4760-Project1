#include "driver.h"

int main(int argc, char*argv[]) {
  	int seconds;
	int opt;

	if(argc == 1){
		ofstream outFile("messages.log");
		logFiles(outFile);
		}
	
	while((opt = getopt(argc, argv, "ht:")) != -1){
		switch(opt){
			case 'h':
				helpMenu();
				break;
			case 't': 
				seconds = atoi(optarg);
				printMsg(seconds);
				break;
			default: 
				exit (EXIT_FAILURE);
				break;
		}
	}

	if((opt = getopt(argc, argv, "ht:")) != 1){
		ofstream outFile(argv[1]);
		logFiles(outFile);
	}
}
