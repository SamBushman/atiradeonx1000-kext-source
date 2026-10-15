/* gui_input.c - tiny synthetic-input helper for the G5 (Tiger): works from a foreground ssh command against the logged-in session (see the project's UI-automation notes).
 *   gui_input click X Y        move + left click at global display coordinates (1920x1080 desktop)
 *   gui_input key CODE [flags] key down + up (virtual key code: 36 = Return, 49 = Space, 53 = Esc)
 * Build on the G5:  gcc -std=gnu99 -o gui_input gui_input.c -framework ApplicationServices */
#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char **argv) {
    if (argc >= 4 && !strcmp(argv[1], "click")) {
        CGPoint p = CGPointMake(atof(argv[2]), atof(argv[3]));
        CGPostMouseEvent(p, true, 1, false); usleep(50000);
        CGPostMouseEvent(p, true, 1, true);  usleep(80000);
        CGPostMouseEvent(p, true, 1, false);
        return 0;
    }
    if (argc >= 3 && !strcmp(argv[1], "key")) {
        CGKeyCode k = (CGKeyCode)atoi(argv[2]);
        CGPostKeyboardEvent((CGCharCode)0, k, true); usleep(60000);
        CGPostKeyboardEvent((CGCharCode)0, k, false);
        return 0;
    }
    fprintf(stderr, "usage: gui_input click X Y | key CODE\n"); return 2;
}
