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
**	int fileExists(string filePath)
**
**	Expects the path of a file.
**
**	Returns 1 if the file exists and 0 if not.
**
*/
int fileExists(string path)
{
	FILE* fp = fopen(path.c_str(), "r");

	if(fp != NULL)
	{
		fclose(fp);
		return 1;
	}

	return 0;
}

int runExecutable(string path, string executableName, ShellData *sd)
{
	char *execName = const_cast<char*>(executableName.c_str());
	char *execNameAndPath = const_cast<char*>((path + executableName).c_str());

	pid_t pid = fork();
	if(pid < 0)
		return errno;
	else if (pid == 0)
	{
		char *argv[] = {execName, NULL};
		execve(execNameAndPath, sd->argv, NULL);
		perror(NULL);
	}
	else
	{
		wait(NULL);
	}

	return 0;
}

/*
**	int findExecutableAndRun(string executableName, ShellData *sd)
**
**	Expects the name of an executable and the ShellData
**
**	Searches for the executable's name in the path given by sd->variables["PATH"]
**	and returns 1 if run successfully, 0 otherwise.
**
*/
int findExecutableAndRun(string executableName, ShellData *sd)
{
	string path;
	path.clear();

	// if the executable name starts with / it's an absolute path
	// and no search is required. Just check if the binary exists and run it
	if(executableName[0] == '/' && fileExists(executableName))
		return runExecutable(path, executableName, sd);

	// if it is not an absolute path search the PATH variable
	// and run the executable if found
	istringstream ss(sd->variables["PATH"]);
	string chunk;

	while(getline(ss, chunk, ':')) {
	    if(fileExists(chunk + executableName))
	    	return runExecutable(chunk, executableName, sd);
	}

	return -1;
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
			cout << GRN << BOLD_ON << " Variables:\n";
			for (auto it = sd->variables.cbegin(); it != sd->variables.cend(); ++it)
    			cout << "    " << (*it).first << " = " << (*it).second << "\n";

    		cout << BOLD_OFF << NRM;
		}
		else
			cout << "set VARIABLE_NAME VARIABLE_VALUE\n";
	}

	// if there is an executable in PATH matching args[0] then run it
	else if(findExecutableAndRun(args[0], sd) != -1)
	{
		return STATUS_RUNNING;
	}
	// if no other action was taken it means the command doesn't exist
	else
		cout << RED << BOLD_ON << "Command does not exist!\n" << BOLD_OFF << NRM;

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