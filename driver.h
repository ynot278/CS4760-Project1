//Author: Tony Pham Sept 14, 2021

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

//get time stamp
char* getTime(){
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}

//convert the message type to words
string convertType(char type){
	string convertType(1, type);
	string converted;
	if (convertType == "I"){
		converted = "INFO";
		return converted;	
	}
	else if (convertType == "W"){
		converted = "WARNING";
		return converted;	
	}
	else if (convertType == "E"){
		converted = "ERROR";
		return converted;	
	}
	else if (convertType == "F"){
		converted = "FATAL";
		return converted;
	}
	else
		perror("Error");
		exit (EXIT_FAILURE);
}

//make file and format type, msg, time to file.
int savelog (string filename, string msg, char type){

	ofstream outfile(filename.c_str());

	string convert = convertType(type);

	if (convert == "INFO" || convert == "WARNING" || convert == "ERROR" || convert == "FATAL"){
		outfile << "[" << convert << "] ";
		outfile << "(" << msg << ") - " ;
	
		char* timer = getTime();
		outfile << timer;
		return 0;
	}else{
		perror("Error");
		return -1;
	}
}

//make empty
void clearlog(string filename){
	ofstream outfile;
	outfile.open(filename, std::ofstream::out | std::ofstream::trunc);
	outfile.close();
}

//print formatted type, msg, time
void getlog(string myText, char type){
	string convert = convertType(type);
	cout << "[" << convert << "] ";
	cout << "(" << myText << ") - ";

	char* timer = getTime();
	cout << timer;
}
