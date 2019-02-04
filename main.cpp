
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#include "version.h"

#if defined _WINDOWS

#else
	#include <unistd.h>
	#include <sys/wait.h>
#endif

#include <iostream>

#include <string>

#if defined _WINDOWS

#else

#endif

std::string globalAnswer="";

void RunApi(const char* command, const char* args);



int main ( int argc, char *argv[] ) {
	printf("\n**** CMD-TOOL v%d.%d ****\n", cmd_tool_VERSION_MAJOR, cmd_tool_VERSION_MINOR);

	if(argc == 3) {
		RunApi(argv[1], argv[2]);
	}
	else {
		std::cout << "Usage:" << std::endl;
		std::cout << "cmd-tool command commandArgs" << std::endl;
	}

	return 0;
}



bool SendCommand(const char* command, const char* args) {
	bool error = false;

	int intCommand = atoi(command);
	switch (intCommand) {
		case 0:
			globalAnswer = "Hello 0";
			break;

		case 1:
			globalAnswer = "Hello 1";
			break;

		default: error = true;
	}


	return !error;
}



void RetrieveAnswer(std::string& answer) {
	answer = globalAnswer;

	std::cout << "Received: \"" << answer << "\"" << std::endl;
}



void RunApi(const char* command, const char* args) {
	if(SendCommand(command, args)) {
		std::string answer;
		RetrieveAnswer(answer);

		std::cout << "ANSWER: " << answer << std::endl;
	}
}

