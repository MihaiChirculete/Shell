/*
**	Part of the Shell Project
**
**	Contributors: 
**		- Chirculete Vlad Mihai
**		- Stanciu Andrei Cristian
**		- Pietreanu Madalina Cristina
**
**	This is the main file of the project.	
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
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
	sd->variables["prompt"] = "> ";		// the shell will crash if there is no prompt is not set

	// check if the shell was called with arguments and take acction accordingly
	if(argc > 1)
	{
		if(strcmp(argv[1], "-h"))
		{
			cout << "Usage: shell SCRIPT_FILE\n";
			cout << "   The SCRIPT_FILE is optional. If it is provided, the shell will attempt to interpret the file and terminate.\n";
			cout << "If no SCRIPT_FILE is provided an interactive shell session will be started.\n";
		}

		// TO-DO: Add check for SCRIPT_FILE argument and interpret the file if found.
	}

	// the main loop of the shell
	shell_loop(sd);

	return EXIT_SUCCESS;
}