/*
**	Part of the Shell Project
**
**	Author: Chirculete Vlad Mihai
**		
**	This is the main file of the project.	
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <errno.h>
#include "utils/colors.h"
#include "data_types/data_types.h"
#include "utils/constants.h"
#include "utils/utils.h"

using namespace std;

int main(int argc, char** argv)
{
	ShellData *sd = new ShellData();
	sd->variables["PROMPT"] = "> ";		// the shell will crash if there is no prompt is not set
	sd->variables["PATH"] = "/usr/bin/:/bin/:/sbin/:";	// the default PATH variable (used to search for binaries)
	char *dir = (char*)malloc(2048);
	getcwd(dir, 2048);
	sd->variables["CURRENT_WORKING_DIR"].assign(dir, 2048);
	sd->argc = argc;	// store the arg count in the shell data object
	sd->argv = argv;	// store the arguments passed to the shell in the shell data object

	// check if the shell was called with arguments and take acction accordingly
	if(argc > 1)
	{
		if(strcmp(argv[1], "-h") == 0)
		{
			cout << "Usage: shell SCRIPT_FILE\n";
			cout << "   The SCRIPT_FILE is optional. If it is provided, the shell will attempt to interpret the file and terminate.\n";
			cout << "If no SCRIPT_FILE is provided an interactive shell session will be started.\n";
			cout << "For more info check the " << BOLD_ON << YEL << "README.md " << BOLD_OFF << NRM << "file in the Shell repository.\n";

			return EXIT_SUCCESS;
		}

		else{
			int ret = runScript(argv[1], sd);
			if(ret == REQUEST_TERMINATE_SHELL)
				return EXIT_SUCCESS;
			else if(ret == EXIT_ERROR)
			{
				cout << RED << BOLD_ON << "An error occured!\n" << BOLD_OFF << NRM;
				return ret;
			}

			return ret;
		}
	}

	// set the signal handler
	signal (SIGINT,sig_handler);

	// the main loop of the shell
	shell_loop(sd);

	return EXIT_SUCCESS;
}
