#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// I got confused reading the rubric and do not know what to do with these
//int addmsg (const char type, const char * msg);
//void clearlog();
//char * getlog();
//int savelog (char * filename);

//struct data_struct{
//	time_t time; 	//time stamp
//	char type; 		//message type (i/w/e/f)
//	char * string; //message string
	
//}data_t;

//I am sorry

void helpMenu(){
	cout << "Usage: driver [-h] [-t sec] [logfile]";
	exit (EXIT_SUCCESS);
}

//Used when ./driver
void logFiles(ofstream &outFile){
	string type;
	string myText;
	string convert;
	ifstream inFile("messages.txt");

	if(!inFile){
		perror("Error");
	}

	while(getline (inFile, myText)){
			time_t now = time(0);
			char* dt = ctime(&now);

			type = myText[0];

			if (myText[0] == 'I'){
				convert = "INFO";
			}
			else if (myText[0] == 'W'){
				convert = "WARN";
			}
			else if (myText[0] == 'E'){
				convert = "ERROR";
			}
			else if (myText[0] == 'F'){
				convert = "FATAL";
				ofstream fatal("savelog");
				myText = myText.substr(2, myText.size());
				fatal << "(" << convert << ")" << "[" << myText << "] - " << dt << endl;
				exit (EXIT_FAILURE);
			}
			else
				perror("Error");

			myText = myText.substr(2, myText.size());
			outFile << "(" << convert << ")" << "[" << myText << "] - " << dt << endl;
		}


}

//Used when ./driver -t sec
void printMsg(int &seconds){
	int delay;
	string type;
	string myText;
	string convert;
	ifstream inFile("messages.txt");

	if(!inFile){
		perror("Error");
	}

	while(getline (inFile, myText)){
			time_t now = time(0);
			char* dt = ctime(&now);

			type = myText[0];

			if (myText[0] == 'I'){
				convert = "INFO";
			}
			else if (myText[0] == 'W'){
				convert = "WARN";
			}
			else if (myText[0] == 'E'){
				convert = "ERROR";
			}
			else if (myText[0] == 'F'){
				convert = "FATAL";
				ofstream fatal("savelog");
				myText = myText.substr(2, myText.size());
				fatal << "(" << convert << ")" << "[" << myText << "] - " << dt << endl;
				exit (EXIT_FAILURE);
			}
			else
				perror("Error");

			myText = myText.substr(2, myText.size());
			cout << "(" << convert << ")" << "[" << myText << "] - " << dt << endl;
			delay = rand() % (2*seconds + 1) + 0;
			sleep(delay);
	}
	cout << "Finished Printing";
	exit (EXIT_SUCCESS);
}


//main
void parseArg(int argc, char *argv[]){
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