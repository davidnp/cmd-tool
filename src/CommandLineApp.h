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
		string ConcatenateVectorToString(vector<string> wordsVector);
		string TestArray(vector<string> parameters);
		string SumVector(vector<string> parameters);
		string SumCIN();

		string HttpTest();
};

#endif //CommandLineAppH