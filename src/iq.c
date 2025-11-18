#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "iq.h"
#include "utils.h"

/* Questions, options and correct answers */
static const char *questions[] = {
    "1. Flow : River :: Stagnant : ?",
    "2. Look at this series: 7, 10, 8, 11, 9, 12, ... What number should come next?",
    "3. Statements:\n   All green are blue.\n   All blue are white.\nConclusions:\n   1. Some blue are green.\n   2. Some white are green.\n   3. Some green are not white.\n   4. All white are blue.",
    "4. 123 : 13^2 :: 235 : ?",
    "5. Look at this series: 53, 53, 40, 40, 27, 27, ... What number should come next?",
    "6. Statements:\n   All the locks are keys.\n   All the keys are bats.\n   Some watches are bats.\nConclusions:\n   1. Some bats are locks.\n   2. Some watches are keys.\n   3. All the keys are locks.",
    "7. Glove : Hand",
    "8. Look at this series: V, VIII, XI, XIV, __, XX, ... What number should fill the blank?",
    "9. Statements:\n   No cows is cats.\n   All the dogs are cats.\nConclusions:\n   1. No cow is dog.\n   2. No dog is cat.\n   3. Some cats are dogs.\n   4. All the cows are dogs.",
    "10. 'Ophthalmia' is related to 'Eye' in the same way as 'Rickets' is related to:",
    "11. Look at this series: VI, 10, V, 11, __, 12, III, ... What number should fill the blank?",
    "12. Statements:\n   Some envelops are gums.\n   Some gums are seals.\n   Some seals are adhesives.\nConclusions:\n   1. Some envelopes are seals.\n   2. Some gums are adhesives.\n   3. Some adhesives are seals.\n   4. Some adhesives are gums."
};

static const char *options[][4] = {
    {"A. Rain", "B. Stream", "C. Canal", "D. Pool"},
    {"A. 7", "B. 10", "C. 12", "D. 13"},
    {"A. Only (1) and (2)", "B. Only (1) and (3)","C. Only (1) and (4)","D. Only (2) and (4)"},
    {"A. 23^2","B. 35^2","C. 25^3","D. 25^2"},
    {"A. 12","B. 14","C. 27","D. 53"},
    {"A. Only (1) and (2)","B. Only (1)","C. Only (2)","D. Only (1) and (3)"},
    {"A. Socks : Feet","B. Tie : Shirt","C. Neck : Collar","D. Coat : Pocket"},
    {"A. IX","B. XXIII","C. XV","D. XVII"},
    {"A. Only (2) and (4)","B. Only (1) and (3)","C. Only (3) and (4)","D. Only (2) and (3)"},
    {"A. Kidney","B. Nose","C. Heart","D. Bone"},
    {"A. 2","B. IV","C. IX","D. 14"},
    {"A. Only (3)","B. Only (1)","C. Only (2)","D. Only (4)"}
};

static const char answers[] = {
    'D','B','A','C','B','B','A','D','D','C','B','A'
};

static int ask_and_score(void)
{
    int i, j;
    int total = 0;

    for (i = 0; i < (int)(sizeof(questions)/sizeof(questions[0])); ++i) {
        clear_screen();
        puts(questions[i]);
        puts("------------------------------------------------------------");
        for (j = 0; j < 4; ++j) {
            puts(options[i][j]);
        }
        puts("------------------------------------------------------------");
        printf("\nYour Guess (A/B/C/D): ");
        int ch = read_choice_char();
        if (!ch) { /* EOF or error */
            puts("\nInput error. Treating as wrong answer.");
            continue;
        }
        if (ch == answers[i]) total += 4;
    }
    return total;
}

static float compute_iq_from_score(int points)
{
    float age = 0.0f;
    while (1) {
        printf("Enter your age (6 - 109): ");
        age = read_float();
        if (age >= 6.0f && age <= 109.0f) break;
        puts("Invalid age; try again.");
    }
    /* IQ formula kept similar to original: (points/age)*100.0 */
    return (points / age) * 100.0f;
}

float run_iq_test(const char *name)
{
    int points = ask_and_score();
    float iq = compute_iq_from_score(points);
    clear_screen();
    if (name && name[0]) {
        printf("%s, your IQ according to your answers is %.2f\n", name, iq);
    } else {
        printf("Your IQ according to your answers is %.2f\n", iq);
    }
    return iq;
}
