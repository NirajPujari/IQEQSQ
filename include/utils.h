#ifndef UTILS_H
#define UTILS_H

void clear_screen(void);
void pause_for_enter(void);
int read_choice_char(void); /* returns uppercase char as int or 0 on EOF */
int read_int(void);
float read_float(void);
void flush_stdin(void);

#endif /* UTILS_H */
