#include "./main.h"

int main()
{
    // Table of pointers to the different functions.
    void (*functions[])(void) = {NULL, mainQuestion1, mainQuestion2, mainQuestion3};
    int userInput = -1;
    do {
        // Showing a prompt to the user
        printf("\nType any number from 1 to 3 to see what the associated exercise main function does. Type 0 to exit.\n");

        // Asking the number of the question he wants to see the answer.
        if (scanf("%d", &userInput) != 1)
        {
            scanf("%*s"); // Consume invalid input
            printf("Invalid input. Please enter a number.\n");
        }
        else if (userInput == 0)
        {
            return 0;
        }
        else if (0 < userInput && 3 >= userInput)
        {
            functions[userInput]();
        }
        else
        {
            printf("Invalid choice.\n");
        }

        // Re-initialize userInput
        userInput = -1;
    } while (1);

    return 0;
}
