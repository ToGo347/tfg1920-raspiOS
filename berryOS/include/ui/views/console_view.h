#ifndef _CONSOLE_VIEW_H
#define _CONSOLE_VIEW_H

#include <ui/view_group.h>

#define CONSOLE_INPUT_HEIGHT 10
#define BG_COLOR GREY

extern VIEW_GROUP consoleView;

void init_console(int width, int height);

#endif /* _CONSOLE_VIEW_H */