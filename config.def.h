/* See LICENSE file for copyright and license details. */

#define black "#181926"
#define pn1 "#2e3440"
#define pn2 "#3b4252"
#define pn3	"#434c5e"
#define pn4 "#4c566a"
#define ss1 "#d8dee9"
#define ss2	"#e5e9f0"
#define ss3 "#eceff4"
#define fr1 "#8fbcbb"
#define fr2 "#88c0d0"
#define fr3 "#81a1c1"
#define fr4 "#5e81ac"
#define au1 "#bf616a"
#define au2 "#d08770"
#define au3 "#ebcb8b"
#define au4 "#a3be8c"
#define au5 "#b48ead"

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const char buttonbar[]            = "﩯";

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const int quit_empty_window_count = 0;   /* only allow dwm to quit if no (<= count) windows are open */
static const char *fonts[]               = { "monospace:size=11:style=bold" };
static const char dmenufont[]            = "monospace:size=11:style=bold";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = ss3;
static char normbgcolor[]                = pn1;
static char normbordercolor[]            = pn4;
static char normfloatcolor[]             = pn3;

static char selfgcolor[]                 = fr2;
static char selbgcolor[]                 = pn1;
static char selbordercolor[]             = ss1;
static char selfloatcolor[]              = ss1;

static char titlenormfgcolor[]           = ss3;
static char titlenormbgcolor[]           = pn1;
static char titlenormbordercolor[]       = pn1;
static char titlenormfloatcolor[]        = au4;

static char titleselfgcolor[]            = ss3;
static char titleselbgcolor[]            = pn1;
static char titleselbordercolor[]        = pn4;
static char titleselfloatcolor[]         = au4;

static char tagsnormfgcolor[]            = pn1;
static char tagsnormbgcolor[]            = fr3;
static char tagsnormbordercolor[]        = fr3;
static char tagsnormfloatcolor[]         = pn1;

static char tagsselfgcolor[]             = ss3;
static char tagsselbgcolor[]             = pn1;
static char tagsselbordercolor[]         = fr3;
static char tagsselfloatcolor[]          = pn1;

static char hidnormfgcolor[]             = au1;
static char hidselfgcolor[]              = au1;
static char hidnormbgcolor[]             = pn1;
static char hidselbgcolor[]              = pn1;

static char urgfgcolor[]                 = pn1;
static char urgbgcolor[]                 = au1;
static char urgbordercolor[]             = au1;
static char urgfloatcolor[]              = au4;

static char scratchselfgcolor[]          = fr2;
static char scratchselbgcolor[]          = pn1;
static char scratchselbordercolor[]      = pn1;
static char scratchselfloatcolor[]       = au3;

static char scratchnormfgcolor[]         = fr2;
static char scratchnormbgcolor[]         = pn1;
static char scratchnormbordercolor[]     = pn1;
static char scratchnormfloatcolor[]      = pn1;



static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },
	[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
};




static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	// [DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[DEFAULT_TAGS]        = { "一", "二", "三", "四", "五", "六", "七", "八", "九" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .scratchkey = 's', .isfloating = 1, .iscentered = 1)
	RULE(.instance = "nextcloud", .iscentered = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *roficmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,             			XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|Mod4Mask,              XK_h,      	   incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_l,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_h,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_l,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask,    			XK_d,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY,             			XK_q,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_plus,       togglescratch,          {.v = scratchpadcmd } },
	{ MODKEY|ControlMask,           XK_F1,		   setscratch,             {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,             XK_F1,         removescratch,          {.v = scratchpadcmd } },
	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = roficmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = 0} },
};

