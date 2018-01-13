/* Include Guard */
#ifndef _SHELL_DATA_TYPES
#define _SHELL_DATA_TYPES
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif

#ifndef _GLIBCXX_MAP
#include <map>
#endif

using namespace std;

class ShellData{
	public:
		int argc;	// arg count
		char **argv;	// args passed to the shell when it is started
		vector<string> cmd_buf;
		map<string, string> variables;	// the SHELL variables
};