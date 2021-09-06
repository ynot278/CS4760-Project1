#include <iostream>
#include <unistd.h>

using namespace std;

void helpMenu(){
	cout << "driver [-h] [-t sec] [logfile]";
}

void parseCommands(int argc, char *argv[]){
	int seconds;
	int opt;

	if(argc == 1){
		cout << "no args";
	}

	while((opt = getopt(argc, argv, "ht:")) != -1){
		switch(opt){
			case 'h':
				helpMenu();
				break;
			case 't':
				seconds = atoi(argv[2]);
				cout << seconds;
				break;
			default:
				cout << "deafult called";
				break;
		}
	}
}

int main(int argc, char*argv[]) {
  parseCommands(argc, argv);
}
