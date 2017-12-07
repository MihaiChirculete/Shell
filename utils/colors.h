/* Include Guard */
#ifndef _SHELL_COLORS
#define _SHELL_COLORS
#endif


// text colors
#define NRM  "\x1B[0m"
#define BLK  "\x1B[30m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

// background colors
#define BGBLK  "\x1B[40m"
#define BGRED  "\x1B[41m"
#define BGGRN  "\x1B[42m"
#define BGYEL  "\x1B[43m"
#define BGBLU  "\x1B[44m"
#define BGMAG  "\x1B[45m"
#define BGCYN  "\x1B[46m"
#define BGWHT  "\x1B[47m"

// other text attributes
#define BOLD_ON "\x1b[1m"		 // Bold on(enable foreground intensity)
#define UNDERLINE_ON "\x1b[4m"	 // Underline on
#define BLINK_ON "\x1b[5m"		 // Blink on(enable background intensity)
#define BOLD_OFF "\x1b[21m"		 // Bold off(disable foreground intensity)
#define UNDERLINE_OFF "\x1b[24m" //	Underline off
#define BLINK_OFF "\x1b[25m"	 // Blink off(disable background intensity)