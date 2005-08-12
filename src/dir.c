/*  DreamChess
**  Copyright (C) 2004  The DreamChess project
**
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 2 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#ifdef _arch_dreamcast

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <kos/fs.h>

int chdir(const char *path)
{
    if (path[0] != '/')
    {
        const char *cur = fs_getwd();
        int len = strlen(cur);
        char *new = malloc(len + strlen(path) + 2);
        strcpy(new, cur);
        if (new[len - 1] != '/')
        {
            new[len] = '/';
            new[len + 1] = '\0';
        }
        strcat(new, path);
        fs_chdir(new);
        return 0;
    }
    fs_chdir(path);
    return 0;
}

#endif

#ifdef __WIN32__

#define USERDIR "DreamChess"

#include <windows.h>
#include <io.h>
#include "shlwapi.h"
#include "shlobj.h"

int ch_datadir()
{
    char filename[MAX_PATH + 6];

    GetModuleFileName(NULL, filename, MAX_PATH);
    filename[MAX_PATH] = '\0';
    PathRemoveFileSpec(filename);
    strcat(filename, "/data");
    return chdir(filename);
}

int ch_userdir()
{
    char appdir[MAX_PATH];

    if (SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, appdir))
        return -1;

    if (chdir(appdir))
        return -1;

    if (chdir(USERDIR))
    {
        if (mkdir(USERDIR))
            return -1;

        return chdir(USERDIR);
    }

    return 0;
}

#else /* !__WIN32__ */

#define USERDIR ".dreamchess"

#include <unistd.h>

int ch_datadir()
{
    return chdir(DATADIR);
}

int ch_userdir()
{
    char *home = getenv("HOME");

    if (!home)
        return -1;

    if (chdir(home))
        return -1;

    if (chdir(USERDIR))
    {
        if (mkdir(USERDIR, 0755))
            return -1;

        return chdir(USERDIR);
    }

    return 0;
}

#endif
