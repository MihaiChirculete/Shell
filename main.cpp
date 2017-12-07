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
#include <string>
#include <vector>
#include "data_types/data_types.h"
#include "utils/constants.h"
#include "utils/utils.h"

using namespace std;

int main(int argc, char** argv)
{
	ShellData *sd = new ShellData();
	sd->variables["prompt"] = "> ";

	// the main loop of the shell
	shell_loop(sd);

	return EXIT_SUCCESS;
}