/* user and group to drop privileges to */
static const char *user  = "ghost";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1a1b26",     /* after initialization */
	[INPUT] =  "#444b6a",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/*Enable blur*/
#define BLUR
/*Set blur radius*/
static const int blurRadius=5;
/*Enable Pixelation*/
//#define PIXELATION
/*Set pixelation radius*/
static const int pixelSize=0;

/* Background image path, should be available to the user above */
static const char* background_image = "/usr/local/bin/background.jpg";

/* default message */
static const char * message = "Hello, Again\nEnter your password";

/* Incorrect password message */
static const char * error_message = "Incorrect Password\nTry again";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "6x10";
