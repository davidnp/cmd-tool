
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
using namespace std;

#include <string>
#include <vector>

#if defined _WINDOWS

#else

#endif

/*
class CommandLineApp {
	public:
		CommandLineApp();
		~CommandLineApp();

		void RunApi(int argc, char *argv[]);

	private:
		bool SendCommand(const char* command, const char* args)
}
*/

std::string globalAnswer="";

void RunApi(int argc, char *argv[]);



int main ( int argc, char *argv[] ) {
	char headerLog[64];
	sprintf(headerLog, "**** CMD-TOOL v%d.%d ****", cmd_tool_VERSION_MAJOR, cmd_tool_VERSION_MINOR);
	string strHeaderLog = headerLog;
	cout << headerLog << endl;

	if(argc >= 2) {
		RunApi(argc, argv);
	}
	else {
		std::cout << "Usage:" << std::endl;
		std::cout << "cmd-tool command commandArgs" << std::endl;
	}

	return 0;
}



bool SendCommand(int command, vector<string> parameters) {
	bool error = false;

	switch (command) {
		case 0:
			globalAnswer = "Hello 0 ";
			break;

		case 1:
			globalAnswer = "Hello 1 ";
			break;

		default: error = true;
	}
	for (auto parameter : parameters) {
		globalAnswer.append(parameter);
	}

	return !error;
}



void RetrieveAnswer(std::string& answer) {
	answer = globalAnswer;

	std::cout << "Received: \"" << answer << "\"" << std::endl;
}



void /*CommandLineApp::*/RunApi(int argc, char *argv[]) {
	int command = atoi(argv[1]);
	vector<string> parameters;
	for (int i = 2; i < argc; i++) {
		parameters.push_back(argv[i]);
	}
	if(SendCommand(command, parameters)) {
		std::string answer;
		RetrieveAnswer(answer);

		std::cout << "ANSWER: " << answer << std::endl;
	}
}

