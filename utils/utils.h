#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif

#ifndef _GLIBCXX_SSTREAM
#include <sstream>
#endif

#ifndef _SHELL_CONSTANTS
#include "constants.h"
#endif

#ifndef _SHELL_UTILS
#define _SHELL_UTILS
#endif

using namespace std;

/*
**	void split_input(string INPUT, vector<string> &ARGS)
**
**	Expects a string that contains the input read from the terminal and a reference to a vector of arguments
** 	which is initially empty.
**
**	At the end of the execution the ARGS vector will contain the split input
*/
void split_input(string input, vector<string> &args)
{
	istringstream ss(input);
	string arg;

	// clear the args vector
	args.clear();

	// parse the input and add the args to the vector
	while(getline(ss, arg, ' ')) {
	    args.push_back(arg);
	}
}


/*
**	int shell_interpret(const vector<string> ARGS)
**
**	Expects a vector of arguments
**
**	Returns a value defined in constants.h
*/
int shell_interpret(const vector<string> args)
{
	if(args[0].compare("exit") == 0)
		return REQUEST_TERMINATE_SHELL;

	return STATUS_RUNNING;
}

int shell_loop()
{
	int status = STATUS_RUNNING;
	string input;
	vector<string> args;

	do
	{
		// clear the input
		input.clear();

		// clear the args
		args.clear();

		// display the prompt
		cout << "> ";

		// read the input
		getline(cin, input);

		// split the input into args
		split_input(input, args);

		// interpret the args
		status = shell_interpret(args);

	}while(status != REQUEST_TERMINATE_SHELL);

	return EXIT_SUCCESS;
}