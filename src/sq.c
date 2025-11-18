#include <stdio.h>
#include <ctype.h>
#include "sq.h"
#include "utils.h"

static const char *questions[] = {
    "01. I love to socialize.",
    "02. I can be comfortable with all types of people - young and old, rich and poor.",
    "03. I always mingle at parties.",
    "04. I can be strongly affected by someone smiling or frowning at me.",
    "05. I usually take the initiative to introduce myself to strangers.",
    "06. I'm generally concerned about the impression I'm making on others.",
    "07. I can easily adjust to being in just about any social situation.",
    "08. When I'm with a group of friends, I am often the spokesperson for the group.",
    "09. At parties, I can immediately tell when someone is interested in me.",
    "10. I can easily tell a person's character by watching them interact with others."
};

static const char *options[] = {
    "A. Exactly like me.", "B. Very close to me.", "C. Sometimes I'm like that.", "D. Very rarely I'm like that.", "E. Not at all like me."
};

static int ask_sq_questions(void)
{
    int total = 0;
    for (int i = 0; i < 10; ++i) {
        clear_screen();
        puts("******************************************************************************");
        puts(questions[i]);
        puts("******************************************************************************");
        for (int j = 0; j < 5; ++j) {
            puts(options[j]);
        }
        puts("------------------------------------------------------------------------------");
        printf("Give your guess (A/B/C/D/E): ");
        int ch = getchar();
        if (ch == EOF) {
            flush_stdin();
            puts("Input error; counting as 'E'.");
            total += 1;
            continue;
        }
        /* consume rest of line */
        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF) { }
        ch = toupper(ch);
        switch (ch) {
            case 'A': total += 5; break;
            case 'B': total += 4; break;
            case 'C': total += 3; break;
            case 'D': total += 2; break;
            case 'E': total += 1; break;
            default: total += 1; break;
        }
    }
    return total;
}

void run_sq_test(void)
{
    int score = ask_sq_questions();
    int age = 0;
    while (1) {
        printf("What is your age? ");
        age = read_int();
        if (age > 0) break;
        puts("Invalid age; try again.");
    }
    /* original code used (count*10)/age; keep similar behaviour */
    int sq = (score * 10) / age;
    puts("\n===============================================================================\n");
    if (sq >= 20 && sq <= 30)
        puts("Your SQ is above 100. You have a High Level of Social Intelligence.");
    else if (sq >= 10 && sq < 20)
        puts("Your SQ is between 85 and 100. You have an Average Level of Social Intelligence.");
    else
        puts("Your SQ is below 85. You have a Below Average Level of Social Intelligence.");
    puts("\n===============================================================================\n");
}
