#include <iostream>

#include "CommandLineApp.h"
#include <array>
#include <algorithm>

CommandLineApp::CommandLineApp() {

}



CommandLineApp::~CommandLineApp() {

}



bool CommandLineApp::SendCommand(int command, vector<string> parameters, string& answer) {
	bool error = false;

	switch (command) {
		case 0:
			answer = "PARAMLIST ";
			answer.append( ConcatenateVectorToString(parameters) );
			
			break;

		case 1:
			answer = "TEST ARRAY ";
			answer.append( TestArray(parameters) );
			break;

		case 2:
			answer = "SUM ";
			answer.append( SumVector(parameters) );
			break;

		case 3:
			answer = "SUM CIN ";
			answer.append( SumCIN() );
			break;

		case 4:
			answer = "HTTP TEST ";
			answer.append( HttpTest() );
			break;

		default: error = true;
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



string CommandLineApp::ConcatenateVectorToString(vector<string> wordsVector) {
	string result;

	//for (auto word : wordsVector) {
	//	result.append(word);
	//} 
	for_each(wordsVector.cbegin(), wordsVector.cend(), [&result, wordsVector](string word){result.append(word);});

	return result;
}



string CommandLineApp::TestArray(vector<string> parameters) {
	const int arraySize = 3;
	array<string, arraySize> iArray;

	copy_n(parameters.cbegin(), arraySize, iArray.begin());
	copy(parameters.begin(), parameters.begin() + arraySize, iArray.begin());
	copy(parameters.begin(), parameters.end(), iArray.begin());

	string result;

	result.append("{");
	result.append(iArray[0]);
	result.append(", ");
	result.append(iArray[1]);
	result.append(", ");
	result.append(iArray[2]);
	result.append("}");

	return result;
}



string CommandLineApp::SumVector(vector<string> parameters) {
	int sum = 0;
	/* for (const auto& param : parameters) {
		sum += atoi(param.c_str());
	}*/
    for_each(parameters.cbegin(), parameters.cend(), [&sum](string item){sum+=atoi(item.c_str());});
	
	string result;
	result.append("SUM ").append(to_string(sum));
	return result;
}

#include <istream>

string CommandLineApp::SumCIN() {
//	auto is = istream_range<string>{cin};

}

class HttpConnection {
	public:
		std::vector<std::string> headers_;
		std::string body_;

		std::string toString() {
			std::string result;
			result.append("HttpConnection { HEADERS(");
			for (auto h : headers_) {
				result.append(" - ").append(h);
			}
			result.append("} BODY {").append(body_).append("}");

			return result;
		}
};

enum BuilderState {
  START,
  HEADER,
  BODY
};

template <BuilderState state>
class HttpConnectionBuilder {
	public:
		HttpConnectionBuilder<HEADER> add_header(std::string header) && {
			static_assert(state == START || state == HEADER, 
      					"add_header can only be called from START or HEADER state");

			headers_.emplace_back(std::move(header));

			return HttpConnectionBuilder<HEADER>{std::move(headers_), std::move(body_)};//std::move(*this);
		}
		// IMPORTANT : must be called after at least one add_header
		HttpConnectionBuilder<BODY> add_body(std::string body) && {
			static_assert(state == HEADER, 
      					"add_body can only be called from HEADER state");

			body_ = std::move(body);

			return HttpConnectionBuilder<BODY>{std::move(headers_), std::move(body_)};//std::move(*this);
		}
		// IMPORTANT : must be called after add_body.
		// Consumes the object.
		HttpConnection build() && {
			return {std::move(headers_), std::move(body_)};
		}
	//private:
		std::vector<std::string> headers_;
		std::string body_;
};

string CommandLineApp::HttpTest() {
	std::string head1("HEAD1");
	std::string head2("HEAD2");
	std::string body("BODY");
	
	HttpConnection test = HttpConnectionBuilder<START>{}.add_header("HEAD1").
								  add_header("HEAD2").
								  add_body("BODY").
								  build();

	return test.toString();
}