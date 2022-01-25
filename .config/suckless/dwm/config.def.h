/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 2;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int minwsz    = 20;       /* Minimal heigt of a client for smfact */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "terminus:style=Regular:size=8:antialias=true:autohint=true", "FontAwesome:style=Regular:size=8:antialias=true:autohint=true", "FontAwesome 4 Free Solid:style=Regular:size=8:antialias=true:autohint=true" };
static const char dmenufont[]       = "terminus:style=Regular:size=8:antialias=true:autohint=true";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char selbordercolor[]  = "#fff000"; //"#ff0000"
static const char col_cyan[]        = "#806000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  selbordercolor  },
};

/* tagging */
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class   			instance	title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    		NULL,		NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", 		NULL,		NULL,           1 << 1,    0,          0,          -1,        -1 },
	{ "Yad",     		"yad",		"YAD", 			0,         1,          0,			0,		  -1 },
	{ "float-term",  	NULL,		NULL, 			0,         1,          0,			0,		  -1 },
	{ "st-256color",	NULL,		NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      		NULL,		"Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "gaplessgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[G]",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands amixer -q sset Master 3%+*/
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *htopcmd[]  = { "st", "-e", "htop", NULL };
static const char *browsercmd[]  = { "firefox", NULL };
static const char *filemgrcmd[]  = { "pcmanfm", NULL };
static const char *guieditorcmd[]  = { "mousepad", NULL };
static const char *slockcmd[]  = { "systemctl", "suspend", NULL };
static const char *fullscrncapture[]  = { "scrot", "/home/ghost/Media/screenshots/%Y-%m-%d-%T-capture.png", NULL }; //don't know why $HOME does not work
static const char *focuscapture[]  = { "scrot", "-u", "/home/ghost/Media/screenshots/%Y-%m-%d-%T-capture.png", NULL };
static const char *selectcapture[]  = { "scrot", "-s", "/home/ghost/Media/screenshots/%Y-%m-%d-%T-capture.png", NULL };
static const char *showkeybindings[]  = { "/home/ghost/.config/suckless/dwm/scripts/keybindings.sh", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
//EMyKeyBindings
	/* modifier                     key        function        argument */
	//Group SpawnPrograms
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,		        		XK_w,	   spawn,          {.v = browsercmd } },
	{ MODKEY,		        		XK_e, 	   spawn,          {.v = filemgrcmd } },
	{ MODKEY,		        		XK_End,    spawn,          {.v = slockcmd } },
	{ MODKEY,		        		XK_s, 	   spawn,          {.v = showkeybindings } },
	{ MODKEY,		        XF86XK_AudioPrev, 	   spawn,          SHCMD("st -c float-term -g 60x15+350+200 powermenu") },
	{ MODKEY|ShiftMask,             XK_e,	   spawn,          {.v = guieditorcmd } },
	//Group VolumeAndBrightness
	{ 0,			        XF86XK_AudioMute,			   spawn,          SHCMD("killsleep && amixer sset Master toggle") },
	{ 0,			        XF86XK_AudioLowerVolume,	   spawn,          SHCMD("killsleep && amixer -q sset Master 5-") },
	{ 0,			        XF86XK_AudioRaiseVolume,	   spawn,          SHCMD("killsleep && amixer -q sset Master 5+") },
	{ 0,			        XF86XK_MonBrightnessDown,	   spawn,          SHCMD("killsleep && xbacklight -dec 10") },
	{ 0,			        XF86XK_MonBrightnessUp,		   spawn,          SHCMD("killsleep && xbacklight -inc 10") },
	//Group ToggleBar
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	//Group StackRotationAndSizeManipulation
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setsmfact,      {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setsmfact,      {.f = -0.05} },
	//Group ZoomAndView
	{ MODKEY|Mod1Mask,              XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	//Gropu KillWindow
	{ MODKEY,		        		XK_q,      killclient,     {0} },
	//Group ChangeLayout
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3] } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	//Group ViewWindowsOnTags
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	//Group MonitorAndTags
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	//Group GapsManipulation
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	//Group TagKeys
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	//Group Restart Dwm
	{ MODKEY|ShiftMask,             XK_x,      quit,           {0} },
	//Group Screenshot
	{ MODKEY,						XK_Print,  spawn,          {.v = fullscrncapture } },
	{ MODKEY|ShiftMask,             XK_Print,  spawn,          {.v = focuscapture } },
	{ MODKEY|ControlMask,		    XK_Print,  spawn,          {.v = selectcapture } },
};
//EndBindings

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = htopcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

