#include <iostream>

#include "version.h"
#include "CommandLineApp.h"


class Point {
	public:
	string y;
	int x;
};


int main ( int argc, char *argv[] ) {
	char headerLog[64];
	sprintf(headerLog, "**** CMD-TOOL v%d.%d.%d ****", 
			cmd_tool_VERSION_MAJOR,
			cmd_tool_VERSION_MINOR,
			cmd_tool_VERSION_PATCH);

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


	///////

	Point p{"2", 3};


	return 0;
}
