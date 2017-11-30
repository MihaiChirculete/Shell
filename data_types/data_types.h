/* Include Guard */
#ifndef _SHELL_DATA_TYPES
#define _SHELL_DATA_TYPES
#endif

using namespace std;

struct ShellData{
	string current_dir;	// the path of the directory we are inside
	string prompt;	// the shell's prompt
};