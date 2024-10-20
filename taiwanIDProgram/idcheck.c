#include "myid.h"

void checkID(const char* id) {      // const char *: make sure char isn't modified.
    printf("Checking ID: %s\n", id);

    // Check length of ID
    if (strlen(id) != 10) {
        printf("Wrong length!\n");
        return;
    }

    // Step 1: Validate the first letter
    int letterCheckValue = toupper(id[0]) - 'A' + 10; // lettervalue - 'A''s 65 + 10, use <ctype.h>'s toupper()
    if (letterCheckValue < 10 || letterCheckValue > 35) {
        printf("First Alphabet isn't right!\n");
        return;
    }
    
    int letterTrueValue = returnFirstChar(letterCheckValue - 10);

    // Step 2: Validate the digits
    for (int i = 1; i < 10; i++) {
        if (!isdigit(id[i])) {
            // Format string: %[parameter][flags][field width][.precision][length]type
            printf("Not digits in 2nd ~ 9th place.\n"); // "!" operator negates this result, so if the character 
            // is not a digit, the expression evaluates to true, and the code inside the if statement is executed.
            return;
        } 
    }

    // Validate the 2nd digit
    if (id[1] != '1' && id[1] != '2' && id[1] != '8' && id[1] != '9') { // remind: check char by char, not by int.
        printf("2nd digit is invalid.\n");
        return;        
    } 
    
    // Step 3: Calculate the checksum
    int weights[11] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1};
    int sum = (letterTrueValue / 10) * weights[0] + (letterTrueValue % 10) * weights[1]; // First character transform.

    for (int i = 1; i < 10; i++) {
        sum += (id[i] - '0') * weights[i + 1]; // Using '0' to convert char to int, weights[i+1] to pair with right weight.
    }

    if (sum % 10 == 0) {
        printf("ID is valid.\n");
        return;
    } else {
        printf("ID is invalid.\n");
        return;
    }
}
