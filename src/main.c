#include <stdio.h>
#include <string.h>
#include "iq.h"
#include "eq.h"
#include "sq.h"
#include "utils.h"

int main(void)
{
    char name[128];
    int choice = 0;

    while (1) {
        clear_screen();
        puts("IQ / EQ / SQ Test Suite");
        puts("-------------------------------------------------");
        puts("1) IQ Test");
        puts("2) EQ Test");
        puts("3) SQ Test");
        puts("4) Exit");
        puts("-------------------------------------------------");
        printf("Choose option: ");
        choice = read_int();

        switch (choice) {
            case 1:
                clear_screen();
                printf("Enter your name: ");
                if (fgets(name, sizeof(name), stdin)) {
                    size_t ln = strlen(name);
                    if (ln && name[ln-1] == '\n') name[ln-1] = '\0';
                } else {
                    name[0] = '\0';
                    flush_stdin();
                }
                run_iq_test(name);
                pause_for_enter();
                break;
            case 2:
                clear_screen();
                run_eq_test();
                pause_for_enter();
                break;
            case 3:
                clear_screen();
                run_sq_test();
                pause_for_enter();
                break;
            case 4:
                puts("Exiting.");
                return 0;
            default:
                puts("Invalid choice. Press Enter to try again.");
                pause_for_enter();
        }
    }

    return 0;
}
