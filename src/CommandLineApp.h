#ifndef CommandLineAppH
#define CommandLineAppH

#include <string>
#include <vector>
using namespace std;

class CommandLineApp {
	public:
		CommandLineApp();
		~CommandLineApp();

		void RunApi(int argc, char *argv[]);

	private:
		bool SendCommand(int command, vector<string> parameters, string& answer);
};

#endif //CommandLineAppH