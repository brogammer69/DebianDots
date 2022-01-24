//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"cpuused",			30,			0},
	{"",		"cputemp",			30,			0},
	{"",		"ram",				30,			0},
	{"",		"brightness",		3600,		0},
	{"",		"wifi_ssid",		60,			0},
	{"",		"hddfree",			3600,		0},
	{"",		"volume",			3600,		0},
	{"",		"battery",			3600,		0},
	{"",		"datetime",			60,			0},

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
