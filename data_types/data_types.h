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
		map<string, string> variables;	// the SHELL variables
};