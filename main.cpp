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
#include "utils/constants.h"
#include "utils/utils.h"

using namespace std;

int main(int argc, char** argv)
{

	// the main loop of the shell
	shell_loop();

	return EXIT_SUCCESS;
}