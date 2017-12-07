#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif

#ifndef _SHELL_CONSTANTS
#include "constants.h"
#endif

#ifndef _SHELL_DATA_TYPES
#include "../data_types/data_types.h"
#endif


#ifndef _SHELL_UTILS
#define _SHELL_UTILS
#endif

using namespace std;


/*
**	int doesExecutableExist(string executableName, ShellData *sd)
**
**	Expects the name of an executable and the ShellData
**
**	Searches for the executable's name in the path given by sd->variables["PATH"]
**	and returns 0 if the executable wasnt found and 1 if it was.
**
*/
int doesExecutableExist(string executableName, ShellData *sd)
{
	return 0;
}

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
	string arg;
	int i = 0;
	char wait_for_closing = 0;	// set to ' or " when encountering a ' or " and set back to 0 when the ending char was encountered
	char c;
	while((c = input[i]) != '\0')
	{
		if((c == '\"' || c == '\'') && wait_for_closing == 0)
			wait_for_closing = c;
		
		else if(c == wait_for_closing)
			wait_for_closing = 0;	// character found, sequence ended

		else if(c != ' ' && wait_for_closing == 0)
			arg += c;

		else if(wait_for_closing != 0)
			arg += c;
		
		else if(arg.length() > 0)
		{
			args.push_back(arg);
			arg.clear();
		}

		i++;
	}

	// push the last built argument (since the loop stops without pushing it when encountering \0)
	args.push_back(arg);
	arg.clear();
}


/*
**	int shell_interpret(const vector<string> ARGS)
**
**	Expects a vector of arguments
**
**	Returns a value defined in constants.h
*/
int shell_interpret(const vector<string> args, ShellData *sd)
{
	if(args[0].compare("exit") == 0)
		return REQUEST_TERMINATE_SHELL;

	// setting shell variables
	else if(args[0].compare("set") == 0)
	{
		if(args.size() == 3)
			sd->variables[args[1]] = args[2];
		else if(args.size() == 1)	// display all the current variables and their values
		{
			cout << "Variables:\n";
			for (auto it = sd->variables.cbegin(); it != sd->variables.cend(); ++it)
    			cout << (*it).first << " = " << (*it).second << "\n";
		}
		else
			cout << "set VARIABLE_NAME VARIABLE_VALUE\n";
	}

	// if there is an executable in PATH matching args[0] then run it
	else if(doesExecutableExist(args[0], sd))
	{

	}
	// if no other action was taken it means the command doesn't exist
	else
		cout << "Command does not exist!\n";

	return STATUS_RUNNING;
}

int shell_loop(ShellData *sd)
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
		cout << sd->variables["prompt"];

		// read the input
		getline(cin, input);

		// split the input into args
		split_input(input, args);

		// interpret the args
		if(args.size() > 0)
			status = shell_interpret(args, sd);

	}while(status != REQUEST_TERMINATE_SHELL);

	return EXIT_SUCCESS;
}