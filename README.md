# Fork of dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X.

## Requirements

In order to build dwm you need the Xlib header files.

## Installation

Edit config.mk to match your local setup (dwm is installed into
the `/usr/local` namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

```bash
make clean install
```

## Running dwm

Add the following line to your .xinitrc to start dwm using startx:

```bash
exec dwm
```

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

```config
DISPLAY=foo.bar:1 exec dwm
```

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

```bash
while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
do
    sleep 1
done &
exec dwm
```

## Configuration

The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

## Patches

This repository was forked from the [dwm-flexipatch project](https://github.com/bakkeby/dwm-flexipatch) and cleaned with the [flexipatch-finalizer](https://github.com/bakkeby/flexipatch-finalizer) script.
The following patches were enabled.

- BAR_LTSYMBOL_PATCH
- BAR_STATUS_PATCH
- BAR_STATUSBUTTON_PATCH
- BAR_STATUS2D_PATCH
- BAR_TAGS_PATCH
- BAR_WINTITLE_PATCH
- BAR_TITLE_LEFT_PAD_PATCH
- BAR_BORDER_PATCH
- BAR_CENTEREDWINDOWNAME_PATCH
- BAR_EWMHTAGS_PATCH
- BAR_IGNORE_XFT_ERRORS_WHEN_DRAWING_TEXT_PATCH
- BAR_PADDING_VANITYGAPS_PATCH
- ATTACHBOTTOM_PATCH
- CENTER_PATCH
- FOCUSONNETACTIVE_PATCH
- FSIGNAL_PATCH
- LOSEFULLSCREEN_PATCH
- NET_CLIENT_LIST_STACKING_PATCH
- ONLYQUITONEMPTY_PATCH
- PERTAG_PATCH
- PERTAG_VANITYGAPS_PATCH
- RENAMED_SCRATCHPADS_PATCH
- RENAMED_SCRATCHPADS_AUTO_HIDE_PATCH
- RESTARTSIG_PATCH
- ROUNDED_CORNERS_PATCH
- TOGGLEFULLSCREEN_PATCH
- VANITYGAPS_PATCH
- VANITYGAPS_MONOCLE_PATCH
- XRDB_PATCH
