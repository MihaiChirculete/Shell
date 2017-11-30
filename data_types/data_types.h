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

using namespace std;

// used for local shell variables
class GenericVariable{
	private:
		string name;
		string value;

	public:
		GenericVariable(string name, string value)
		{

			this->name = name;
			this->value = value;
		}

		string getName()
		{
			return this->name;
		}

		string getValue()
		{
			return this->value;
		}

		void setName(string name) { this->name = name; }
		void setValue(string value) { this->value = value; }
};

class ShellData{
	public:
		string current_dir;	// the path of the directory we are inside
		string prompt;	// the shell's prompt
		string PATH;	// the PATH variable of the shell (where executables will be searched)
};