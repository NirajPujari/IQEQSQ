/* utils.c - implement utils.h */
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* clear screen cross-platform */
void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    /* try clear, if not available just print newlines */
    if (system("clear") != 0) {
        for (int i = 0; i < 50; ++i) putchar('\n');
    }
#endif
}

/* simple "press Enter to continue" */
void pause_for_enter(void)
{
    puts("\nPress Enter to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* read a single letter choice; returns uppercase letter or 0 on EOF */
int read_choice_char(void)
{
    int c = getchar();
    if (c == EOF) return 0;
    /* consume rest of line */
    int extra;
    while ((extra = getchar()) != '\n' && extra != EOF) { }
    return toupper(c);
}

/* read int robustly (consume trailing newline) */
int read_int(void)
{
    int x;
    if (scanf("%d", &x) == 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
        return x;
    } else {
        /* clear bad input */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
        return -1;
    }
}

/* read float robustly */
float read_float(void)
{
    float f;
    if (scanf("%f", &f) == 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
        return f;
    } else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
        return -1.0f;
    }
}

/* flush remaining stdin */
void flush_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
