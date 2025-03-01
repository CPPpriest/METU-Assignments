#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global random number for phase 1
int random_number;

// Function to initialize the bomb
void initialize() {
    // Set the random number for phase 1
    srand(12);
    random_number = rand() % 1000;  // Let's limit the random number to 3 digits for simplicity
}

// Function to "explode" the bomb
void explode_bomb() {
    printf("BOOM!\n");
    exit(1);
}

// Phase 0: Check string
int strings_not_equal(const char *string1, const char *string2) {
    return strcmp(string1, string2) != 0;
}

void phase_0(char *input) {
    const char* password = "test";
    if (strings_not_equal(input, password)) {
        explode_bomb();
    }
}

// Phase 1: Check for the correct random integer
void phase_1(char *input) {
    int user_input;
    if (sscanf(input, "%d", &user_input) != 1 || user_input != random_number) {
        explode_bomb();
    }
}

// Phase 2: Recursive function
int func1(int i) {
    if (i <= 1) return 1;
    return i * func1(i - 1);
}

void phase_2(char *input) {
    int user_input;
    if (sscanf(input, "%d", &user_input) != 1 || func1(user_input) != 120) {
        explode_bomb();
    }
}

int main() {
    char input[256];

    initialize();
    printf("Welcome to the simplified bomb!\n");

    // Phase 0
    printf("Enter the secret input for phase 0: ");
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;
    phase_0(input);

    printf("Phase 0 defused!\n");

    // Phase 1
    printf("Enter the secret input for phase 1: ");
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;
    phase_1(input);

    printf("Phase 1 defused!\n");

    // Phase 2
    printf("Enter the next input for phase 2: ");
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;
    phase_2(input);

    printf("Phase 2 defused! Congratulations!\n");

    return 0;
}

