
Debian
====================
This directory contains files used to package helixd/helix-qt
for Debian-based Linux systems. If you compile helixd/helix-qt yourself, there are some useful files here.

## helix: URI support ##


helix-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install helix-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your helixqt binary to `/usr/bin`
and the `../../share/pixmaps/helix128.png` to `/usr/share/pixmaps`

helix-qt.protocol (KDE)

