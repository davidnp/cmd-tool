#include <iostream>

#include "version.h"
#include "CommandLineApp.h"

int main ( int argc, char *argv[] ) {
	char headerLog[64];
	sprintf(headerLog, "**** CMD-TOOL v%d.%d ****", cmd_tool_VERSION_MAJOR, cmd_tool_VERSION_MINOR);
	string strHeaderLog = headerLog;
	cout << headerLog << endl;

	if(argc >= 2) {
		CommandLineApp app;
		app.RunApi(argc, argv);
	}
	else {
		std::cout << "Usage:" << std::endl;
		std::cout << "cmd-tool command commandArgs" << std::endl;
	}

	return 0;
}
