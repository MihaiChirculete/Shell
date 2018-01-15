# Shell Project
    To compile: make
    To compile and run: make run
    To clean the project: make clean

# Commands currently implemented
    set VARIABLE_NAME VARIABLE_VALUE:	sets a shell variable
    exit: terminates the shell

# Features currently present
    The shell allows executing external programs if they are found in any of the paths specified by the $PATH variable. 
    Variables from within the shell can be passed to external programs by passing the $VARNAME to the program.

    Example:
	echo $VARNAME
	mkdir $DIR_NAME
	(and so on)

