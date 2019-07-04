#include <iostream>

#include "CommandLineApp.h"

CommandLineApp::CommandLineApp() {

}

CommandLineApp::~CommandLineApp() {

}

bool CommandLineApp::SendCommand(int command, vector<string> parameters, string& answer) {
	bool error = false;

	switch (command) {
		case 0:
			answer = "Hello 0 ";
			break;

		case 1:
			answer = "Hello 1 ";
			break;

		default: error = true;
	}
	for (auto parameter : parameters) {
		answer.append(parameter);
	}

	return !error;
}



void CommandLineApp::RunApi(int argc, char *argv[]) {
	int command = atoi(argv[1]);
	vector<string> parameters;
	for (int i = 2; i < argc; i++) {
		parameters.push_back(argv[i]);
	}

	string answer;
	if(SendCommand(command, parameters, answer)) {
		std::cout << "ANSWER: " << answer << std::endl;
	}
}
