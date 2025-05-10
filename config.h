/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 07;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 07;       /* vert inner gap between windows */
static const unsigned int gappoh    = 05;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 05;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Iosevka Nerd Font:weight=bold:size=11:antialias=true:hinting=true", "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true", };
static const char dmenufont[]       = "Iosevka Nerd Font:size=12:weight=bold";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL};
const char *spcmd2[] = {"st", "-n", "spmusic", "-g", "120x34", "-e", "/home/karna/.ncmpcpp/scripts/ncmpcpp-art", NULL};
const char *spcmd3[] = {"qalculate-gtk", NULL};
const char *spcmd4[] = {"st", "-n",     "spnews", "-f",       "Iosevka Nerd Font:weight=bold:size=12", "-g", "120x34", "-e",     "newsboat", NULL};
const char *spcmd5[] = {"st", "-n", "spchess", "-g", "135x35", "-e", "/home/karna/apps/chess-linux-x64/chess", NULL};

static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm"   ,    spcmd1}, 
    {"spmusic"  ,    spcmd2}, 
    {"spcal"    ,    spcmd3},
    {"spgpt"    ,    spcmd4},  
    {"spnews"   ,    spcmd5},
};

/* tagging */
static const char *tags[]         = { "", "", "", "","", "","", "", "" };
static const char *tagsalt[]      = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const Rule rules[] = {
	/* class              instance        title           tags mask     isfloating  isterminal  noswallow  monitor  floatx  floaty  floatw  floath  floatborderpx */
	{ "Gimp",             NULL,           NULL,           1 << 4,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Firefox",          NULL,           NULL,           1 << 7,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },

	{ "TelegramDesktop",  NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Pavucontrol",      NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Blueman-manager",  NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      800,    800,    0 },
	{ "baobab",           NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "qBittorrent",      NULL,           NULL,           1 << 5,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "pinentry-qt",      NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Qalculate-gtk",    NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "chess-nativefier-703820", NULL,    NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Gnome-disks",      NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Nm-connection-editor", NULL,       NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "flameshot",        NULL,           NULL,           0,            1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "obs",              NULL,           NULL,           1 << 7,       1,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Brave-browser",    NULL,           NULL,           1 << 1,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "Vivaldi-stable",   NULL,           NULL,           1 << 1,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },
	{ "discord",          NULL,           NULL,           1 << 5,       0,          0,          0,         -1,      0,      0,      0,      0,      0 },

	{ "St",               NULL,           NULL,           0,            0,          1,          0,         -1,      0,      0,      0,      0,      0 },
	{ "kitty",            NULL,           NULL,           0,            0,          1,          0,         -1,      0,      0,      0,      0,      0 },
	{ NULL,               NULL,           "Event Tester", 0,            0,          0,          1,         -1,      0,      0,      0,      0,      0 },

	{ NULL,               "spterm",       NULL,           SPTAG(0),     1,          1,          0,         -1,      200,    200,    800,    600,    4 },
	{ NULL,               "spmusic",      NULL,           SPTAG(1),     1,          1,          0,         -1,      300,    200,    900,    600,    4 },
	{ "Qalculate-gtk",    NULL,           NULL,           SPTAG(2),     1,          0,          0,         -1,      350,    250,    600,    400,    4 },
	{ NULL,               "spnews",       NULL,           SPTAG(3),     1,          1,          0,         -1,      400,    300,    900,    600,    4 },
	{ NULL,               "spchess",      NULL,           SPTAG(4),     1,          1,          0,         -1,      450,    350,    1000,   700,    4 },
};


/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[\\]",     dwindle }, /* first entry is default */
	{ "[]=",      tile },    
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static char dmenuprompt[] = "Search: ";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-l", "10", "-p", dmenuprompt, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,		        XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
	{ MODKEY,                       XK_s,      togglesticky,   {0} },

  // Scratchpads
  { 0,                            XK_F12,    togglescratch,          {.ui = 0} },
  { MODKEY|ShiftMask,             XK_m,      togglescratch,          {.ui = 1} },
  { MODKEY,                       XK_c,      togglescratch,          {.ui = 2} },
  { MODKEY|Mod1Mask,              XK_n,      togglescratch,          {.ui = 3} },
//  { 0,                            XK_F11,    togglescratch,          {.ui = 4} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

