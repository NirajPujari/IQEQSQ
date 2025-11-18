#include <stdio.h>
#include <ctype.h>
#include "eq.h"
#include "utils.h"

static const char *questions[] = {
    "01. Your coworker has an annoying habit that seems to get worse everyday, What will you do?",
    "02. What do you do under a lot of pressure?",
    "03. What do you do when taking important decisions?",
    "04. Imagine you want to sell a product by calling, even after calling more than 10 people you find you unsuccessful, you start to feel discouraged, what will you do?",
    "05. What do you do in a very heated argument?",
    "06. If you are asked to do something that you do not like, what will you do?",
    "07. What do you do if two of your friends are arguing?",
    "08. How do you feel when someone criticizes you?",
    "09. Do you try to see the situation from the perspective of other person?",
    "10. If a person breaks your trust, how do you see him?"
};

static const char *options[] = {
    "A. Tell him what's bothering you.", "B. Suffer in silence.", "C. Complain to boss.", "D. Talk behind his back.",
    "A. Stay calm.", "B. Can't find anything to be done.", "C. Get distracted.", "D. Get anxious.",
    "A. Think thoughtfully then choose.", "B. Choose randomly.", "C. Don't think much.", "D. Let someone else decide.",
    "A. Find your mistake and change it.", "B. Stop work for today.", "C. Change concept and try something different.", "D. Give your work to someone else.",
    "A. Hear the other person's point and try to explain yours.", "B. Stop responding / Just try to prove yourself without listening.", "C. Apologize and end the argument.", "D. Start insulting.",
    "A. Let that person know you don't like the work and then do it well.", "B. Just do that work.", "C. Do the work whole-heartedly or say no.", "D. Try to avoid that work.",
    "A. Try to solve the problem and help them calm.", "B. Avoid both.", "C. Be there and try to calm them and let them resolve it.", "D. Pick a side and abuse the other.",
    "A. Listen and try to improve.", "B. Get hurt and overthink.", "C. Ignore criticism.", "D. Retaliate with bad language.",
    "A. Always.", "B. In very specific moments only.", "C. Sometimes.", "D. Never.",
    "A. After apology give them one more chance.", "B. Avoid them and pretend everything is fine.", "C. Never talk to them again.", "D. Don't care."
};

static int ask_eq_questions(void)
{
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        clear_screen();
        puts("==============================================================================");
        puts(questions[i]);
        puts("------------------------------------------------------------------------------");
        for (int j = 0; j < 4; ++j) {
            puts(options[i*4 + j]);
        }
        puts("------------------------------------------------------------------------------");
        printf("Give your guess (A/B/C/D): ");
        int ch = read_choice_char();
        if (!ch) {
            puts("Input error; counting as lowest option.");
            count += 1;
            continue;
        }
        switch (ch) {
            case 'A': count += 4; break;
            case 'B': count += 2; break;
            case 'C': count += 3; break;
            case 'D': count += 1; break;
            default: puts("Invalid option; counted as 1."); count += 1;
        }
    }
    return count;
}

void run_eq_test(void)
{
    int score = ask_eq_questions();
    puts("\n===============================================================================\n");
    if (score > 36 && score <= 40)
        puts("Your EQ is above 145. You have Exceptional Emotional Intelligence.");
    else if (score > 32 && score <= 36)
        puts("Your EQ is between 130 and 145. You have Excellent Emotional Intelligence.");
    else if (score > 28 && score <= 32)
        puts("Your EQ is between 115 and 130. You have High Emotional Intelligence.");
    else if (score > 24 && score <= 28)
        puts("Your EQ is between 100 and 115. You have Satisfactory Emotional Intelligence.");
    else if (score > 20 && score <= 24)
        puts("Your EQ is between 85 and 100. You have Average Emotional Intelligence.");
    else
        puts("Your EQ is below 85. You have very low Emotional Intelligence.");
    puts("\n===============================================================================\n");
}
